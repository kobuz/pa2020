#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> Coord;
typedef pair<int, int> Result;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string > world_map;
    string input;
    map<Coord, Result> results;
    results[{0, 0}] = {0, 0};
    for(int i = 0; i < n; ++i) { // map
        cin >> input;
        world_map.push_back(input);
    }
    
    queue<Coord> q;
    q.push({0, 0});
    Coord changes[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty()) {
        Coord node = q.front();
        q.pop();
        int x = get<0>(node), y = get<1>(node);
        Result res = results[{x, y}];
        int ups = get<0>(res), downs = get<1>(res);
        for(auto delta: changes) {
            int dx = get<0>(delta), dy = get<1>(delta);
            int xx = x + dx, yy = y + dy;
            if(xx < 0 || xx >= m || yy < 0 || yy >= n || world_map[yy][xx] == 'X' || results.find({xx, yy}) != results.end() ) {
                continue;
            }
            int nups = ups + ((dx + dy) > 0 ? 1 : 0), ndowns = downs + ((dx + dy) < 0 ? 1 : 0);
            results[{xx, yy}] = {nups, ndowns};
            q.push({xx, yy});
        }
    }

    Result sol = results[{m - 1, n - 1}];
    int up = get<0>(sol), down = get<1>(sol);
    int a, b;
    vector<int> times;
    for(int i = 0; i < k; ++i) { // travellers
        cin >> a >> b;
        times.push_back(a * up + b * down);
    }
    sort(times.begin(), times.end());
    int winners = 1;
    for(int i = 1; i < k; ++i) {
        if(times[i] == times[i - 1]) {
            ++winners;
        } else {
            break;
        }
    }
    cout << times[0] << " " << winners << endl;
}
