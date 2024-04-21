#include <bits/stdc++.h>
#define N 105
using namespace std;

char a[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bitset<N> vis[N];

void solve() {
  int n, m, sx, sy;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'S') sx = i, sy = j;
      }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) vis[i].reset();
    q.push({sx, sy});
    bool f = false;
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second; q.pop();
      if (a[x][y] == 'T') {
        f = true;
        break;
      }
      if (vis[x][y]) continue;
      vis[x][y] = true;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] == '#') continue;
        q.push({xx, yy});
      }
    }
    cout << (f ? "YES" : "NO") << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("5.in", "r", stdin);
  freopen("5.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}