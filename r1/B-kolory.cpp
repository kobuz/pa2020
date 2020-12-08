#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int, int> event;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int l, r, k;
    vector<event> events;
    for(int i = 0; i < m; ++i) {
        cin >> l >> r >> k;
        events.push_back(make_tuple(l, 0, k));
        events.push_back(make_tuple(r + 1, 1, k));
    }
    sort(events.begin(), events.end());
    int red = 0, blue = 0, yellow = 0;
    int total = 0, prev = 0;
    for(auto &e: events) {
        int pos = get<0>(e), type = get<1>(e), color = get<2>(e);
        if(red == 0 && blue > 0 && yellow > 0) {
            total += pos - prev;
        }
        int sign = (type == 0) ? 1 : -1;
        if(color == 1) {
            yellow += sign;
        }
        else if(color == 2) {
            blue += sign;
        }
        else {
            red += sign;
        }
        prev = pos;
    }
    cout << total << endl;
}
