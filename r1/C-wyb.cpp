#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef tuple<int, int, int> event;

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string task;
    map<string, int> count;
    bool ok = true;
    for(int i = 0; i < n; ++i) {
        cin >> task;
        ++count[task];
    }
    for(char round = '1'; round <= '4' && ok; ++round) {
        for(char div = 'A'; div <= 'C'; ++div) {
            task = string() + round + div;
            if(count.find(task) == count.end()) {
                ok = false;
                break;
            }
        }
    }
    if(count[string("5A")] < 2 || count[string("5B")] < 2 || count[string("5C")] < 2) {
        ok = false;
    }
    if(ok) {
        cout << "TAK" << endl;
    } else {
        cout << "NIE" << endl;
    }
}
