#include <iostream>
using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    int k;
    cin >> k;
    int pow = 1, base = 0, root = 1;
    while(pow < k) {
        ++base;
        pow <<= 1;
    }
    if(pow > k) {
        --base;
        pow >>= 1;
    }
    int last_node = 2 * base + 2;
    // cout << "debug max power of two=" << pow << " base=" << base << " last node=" << last_node << endl;
    cout << last_node << endl;
    pow = 1;
    while(base > 0) {
        // cout << "iter pow=" << pow << endl;
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
