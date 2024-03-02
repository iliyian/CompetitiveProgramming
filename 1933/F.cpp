// date: 2024-03-02 22:08:58
// tag: bfs
// 后面修改那段才是精髓
// 顺便bfs竟然还可以这样写也是nb

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector dis(n, vector<int>(m, -1));
  for (int  i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  dis[0][0] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (a[(x + 1) % n][y] == 0 && a[(x + 2) % n][y] == 0 && dis[(x + 2) % n][y] == -1) {
      dis[(x + 2) % n][y] = dis[x][y] + 1;
      q.push({(x + 2) % n, y});
    }
    if (a[(x + 1) % n][(y + 1) % m] == 0 && dis[(x + 1) % n][(y + 1) % m] == -1) {
      dis[(x + 1) % n][(y + 1) % m] = dis[x][y] + 1;
      q.push({(x + 1) % n, (y + 1) % m});
    }
  }
  // int ans = dis[n - 1][m - 1];
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    int d = dis[i][m - 1];
    if (d != -1) {
      // upwards to the target
      if (d % n != (i + 1) % n) {
        ans = min(ans, d + (i + 1 - d % n + n) % n);
      } else {
        ans = min(ans, d);
      }
    }
  }
  cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}