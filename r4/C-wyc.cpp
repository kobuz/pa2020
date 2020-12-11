#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> Coord;

int n, m, k;


int pack(int x, int y) {
    return x + m * y;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    vector<string > world_map;
    string input;
    vector<int> ups(m * n, -1), downs(m * n, -1);
    ups[0] = downs[0] = 0;
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
        int x = node.first, y = node.second;
        int sup = ups[pack(x, y)], sdown = downs[pack(x, y)];
        for(auto delta: changes) {
            int dx = delta.first, dy = delta.second;
            int xx = x + dx, yy = y + dy;
            if(xx < 0 || xx >= m || yy < 0 || yy >= n || world_map[yy][xx] == 'X' || ups[pack(xx, yy)] != -1 ) {
                continue;
            }
            int nups = sup + ((dx + dy) > 0 ? 1 : 0), ndowns = sdown + ((dx + dy) < 0 ? 1 : 0);
            ups[pack(xx, yy)] = nups;
            downs[pack(xx, yy)] = ndowns;
            q.push({xx, yy});
        }
    }

    int up = ups[pack(m - 1, n - 1)], down = downs[pack(m - 1, n - 1)];
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
