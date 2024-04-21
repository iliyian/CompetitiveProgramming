// date: 2024-04-08 21:54:26
// tag: 状压dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> g(1 << n);
  for (int S = (1 << n) - 1; S > 0; S--) {
    for (int i = 0; i < m; i++) {
      int nxt = S;
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 1) {
          nxt = (nxt | (1 << j)) ^ (1 << j);
        } else if (a[i][j] == -1) {
          nxt = (nxt | (1 << j));
        }
      }
      g[S].push_back(nxt);
    }
  }
  queue<pair<int, int>> q;
  q.push({(1 << n) - 1, 0});
  vector<bool> vis(1 << n);
  while (!q.empty()) {
    auto [u, t] = q.front(); q.pop();
    if (!u) {
      cout << t << '\n';
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (int v : g[u]) {
      q.push({v, t + 1});
    }
  }
  cout << -1 << '\n';

  return 0;
}