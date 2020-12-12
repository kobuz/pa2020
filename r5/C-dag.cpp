#include <iostream>
using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    long long k;
    cin >> k;
    long long pow = 1;
    int base = 0, root = 1;
    while(pow < k) {
        ++base;
        pow <<= 1;
    }
    if(pow > k) {
        --base;
        pow >>= 1;
    }
    int last_node = 2 * base + 2;
    cout << last_node << endl;
    pow = 1;
    while(base > 0) {
        cout << root + 1 << " " << root + 2 << endl;
        if(k & pow) {
            cout << root + 2 << " " << last_node << endl;
        } else {
            cout << root + 2 << " " << -1 << endl;
        }
        root += 2;
        pow <<= 1;
        --base;
    }
    cout << last_node << " -1" << endl;  // helper node
    cout << "-1 -1" << endl;  // last node
}
