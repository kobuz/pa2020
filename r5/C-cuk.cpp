#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000000 + 7;


int main() {
    std::ios::sync_with_stdio(false);
    int n, a;
    cin >> n;
    vector<int> bags;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        bags.push_back(a);
    }
    sort(bags.begin(), bags.end());
    int total = 0; // maximum value to achieve
    for(int i = 0; i < n; ++i) {
        if(bags[i] > total + 1) {
            break;
        }
        total += bags[i];
    }
    vector<vector<long long> > counts;
    counts.resize(n + 1);
    counts[0].resize(total + 1, 0); // init row no items with zeros
    counts[0][0] = 1;
    long long result = 0, new_size, candidate;
    vector<long long> besties, next_besties;
    besties.resize(total + 1, 0);
    besties[0] = 1;
    next_besties.resize(total + 1, 0);
    next_besties[0] = 1;
    for(int item = 1; item <= n; ++item) {
        counts[item].resize(total + 1, 0);
        counts[item][0] = 1;
        int bag_size = bags[item - 1];
        for(int size = 1; size <= total; ++size) {
            candidate = 0;
            if(bag_size > size) { // doesn't fit
                new_size = counts[item - 1][size];
            } else {
                if(counts[item - 1][size - bag_size] > 0) {
                    candidate = counts[item - 1][size - bag_size];
                }
                new_size = counts[item - 1][size] + candidate;
                new_size %= MOD;
                if(candidate > 0 && size + 1 >= 2 * bag_size && besties[size - bag_size] > 0) { // hooray
                    next_besties[size] += besties[size - bag_size];
                    next_besties[size] %= MOD;
                    result += besties[size - bag_size];
                    result %= MOD;
                }
            }
            if(new_size == 0) {
                break;
            }
            counts[item][size] = new_size;
        }
        for(int i = 1; i <= total; ++i) {
            besties[i] = next_besties[i];
        }
    }
    cout << result << endl;
}
