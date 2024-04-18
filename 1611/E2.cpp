// date: 2024-04-17 11:24:49
// tag: bfs，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  queue<pair<int, int>> q;
  bitset<200005> vis;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    q.push({x, 0});
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
  }
  vector<int> dis(n + 1);
  while (!q.empty()) {
    auto [u, d] = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    dis[u] = d;
    for (int v : g[u]) {
      if (!vis[v]) {
        q.push({v, d + 1});
      }
    }
  }
  vis.reset();
  int cnt = 0;
  q.push({1, 0});
  while (!q.empty()) {
    auto [u, d] = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    if (dis[u] <= d) {
      cnt++;
      continue;
    }
    if (u != 1 && in[u] == 1) {
      cout << -1 << '\n';
      return;
    }
    for (int v : g[u]) {
      if (!vis[v]) {
        q.push({v, d + 1});
      }
    }
  }
  cout << cnt << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E2.in", "r", stdin);
  freopen("E2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}