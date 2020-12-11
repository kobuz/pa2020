#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int n, m;
long long p;


void print(int round, long long *ptr) {
    cout << "round " << round << endl;
    for(int lvl = 0; lvl < m; ++lvl) {
        cout << lvl << " : " << ptr[lvl] << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    long long res1[m], res2[m];
    long long *prev = res1, *next = res2;
    for(int lvl = 0; lvl < m; ++lvl) {
        prev[lvl] = m - lvl;
    }
    // print(0, prev);
    for(int i = 1; i < n; ++i) {
        cout << i << endl;
        for(int lvl = 0; lvl < m; ++lvl) { // reset 
            next[lvl] = 0;
        }
        for(int lvl = 0; lvl < m; ++lvl) {
            int h_count = m - lvl;
            long long base;
            // cout << "lvl=" << lvl << endl;
            for(int prev_lvl = 0; prev_lvl < lvl; ++prev_lvl) { // prev started at lower level
                base = ((prev[prev_lvl] - prev[m - prev_lvl - 1] + p) % p);
                // cout << "I prev_lvl=" << prev_lvl << " part=" << part << " h_count=" << h_count << endl;
                next[lvl] += base * h_count;
                next[lvl] %= p;
            }
            for(int prev_lvl = lvl; prev_lvl < m; ++prev_lvl) { // prev started at the same level or higher
                base = prev[prev_lvl];
                // cout << "II prev_lvl=" << prev_lvl << " part=" << part << " h_count=" << h_count << endl;
                next[lvl] += base * h_count;
                next[lvl] %= p;
                h_count -= 1;
            }
        }
        // print(i, next);
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
