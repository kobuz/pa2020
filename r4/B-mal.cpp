#include <iostream>
#include <algorithm>
using namespace std;


int n, m;
long long p;


int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    long long res1[m], res2[m];
    long long *prev = res1, *next = res2;
    for(int lvl = 0; lvl < m; ++lvl) {
        prev[lvl] = m - lvl;
    }
    long long sums[m], woos[m];
    for(int i = 1; i < n; ++i) {
        for(int lvl = 0; lvl < m; ++lvl) { // reset 
            next[lvl] = sums[lvl] = woos[lvl] = 0;
        }
        sums[0] = prev[0];
        woos[m - 1] = prev[m - 1];
        for(int lvl = 1; lvl < m; ++lvl) { // prefix sums and the other thing for speedup
            sums[lvl] = sums[lvl - 1] + prev[lvl];
            sums[lvl] %= p;
            woos[m - lvl - 1] = woos[m - lvl] + ((lvl + 1) * prev[m - lvl - 1]) % p;
            woos[m - lvl - 1] %= p;
        }
        for(int lvl = 0; lvl < m; ++lvl) { // main calculations
            if(lvl > 0) {
                next[lvl] = p + (sums[lvl - 1] - (sums[m - 1] - sums[m - lvl - 1])) * (m - lvl);
                next[lvl] %= p;
            }
            next[lvl] += woos[lvl];
            next[lvl] %= p;
        }
        long long *tmp = prev; // switch pointers
        prev = next;
        next = tmp;
    }
    long long total = 0;
    for(int lvl = 0; lvl < m; ++lvl) {
        total += prev[lvl];
        total %= p;
    }
    cout << total << endl;
}
