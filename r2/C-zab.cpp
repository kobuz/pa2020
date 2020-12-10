#include <iostream>
#include <tuple>
#include <map>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<pair<char, int>, int> s1, s2;
    char c;
    for(int i = 0; i < n; ++i) {
        cin >> c;
        s1[{c, i % 2}] += 1;
    }
    for(int i = 0; i < n; ++i) {
        cin >> c;
        s2[{c, i % 2}] += 1;
    }
    if(s1 == s2) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }
    return 0;
}
