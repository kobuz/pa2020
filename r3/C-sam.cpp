#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, r, w, t, kls;
    cin >> n;
    map<pair<int, int>, int> count;
    set<int> classes;
    for(int i = 0; i < n; ++i) {
        cin >> r >> w >> t;
        kls = w - t;
        count[{kls, r}] += 1;
        classes.insert(kls);
    }
    int removed = 0;
    for(auto kls: classes) {
        removed += min(count[{kls, 1}], count[{kls, 2}]);
    }
    cout << removed << endl;
}
