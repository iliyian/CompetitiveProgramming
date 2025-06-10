#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
void solve() {
    int c, h;
    cin >> c >> h;
    int corners[4][2];
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 4; ++i) {
        corners[i][0] = x;
        corners[i][1] = y;
    }
    for (int i = 1; i < c; ++i) {
        cin >> x >> y;
        if (x + y < corners[0][0] + corners[0][1]) {
            corners[0][0] = x;
            corners[0][1] = y;
        }
        if (x + y > corners[1][0] + corners[1][1]) {
            corners[1][0] = x;
            corners[1][1] = y;
        }
        if (x - y < corners[2][0] - corners[2][1]) {
            corners[2][0] = x;
            corners[2][1] = y;
        }
        if (x - y > corners[3][0] - corners[3][1]) {
            corners[3][0] = x;
            corners[3][1] = y;
        }
    }
    int ans = 0;
    int min_dist = -1;
    for (int i = 0; i < h; ++i) {
        cin >> x >> y;
        int dist = 0;
        for (int j = 0; j < 4; ++j) {
            dist = max(dist, abs(corners[j][0] - x) + abs(corners[j][1] - y));
        }
        if (dist < min_dist || min_dist == -1) {
            min_dist = dist;
            ans = i;
        }
    }
    cout << min_dist << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}