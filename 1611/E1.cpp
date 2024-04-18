// date: 2024-04-16 21:24:14
// tag: bfs

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  bitset<200005> isf;
  queue<pair<int, int>> q;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    q.push({x, 0});
  }
  vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
  }
  vector<int> dis(n + 1, INT_MAX);
  bitset<200005> vis;
  while (!q.empty()) {
    auto [u, t] = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;

    dis[u] = t;
    for (int v : g[u]) {
      if (!vis[v]) {
        q.push({v, t + 1});
      }
    }
  }
  q.push({1, 0});
  vis.reset();
  vector<int> d(n + 1);
  while (!q.empty()) {
    auto [u, t] = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    d[u] = t;
    for (int v : g[u]) {
      if (!vis[v]) {
        q.push({v, t + 1});
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (in[i] == 1 && d[i] < dis[i]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E1.in", "r", stdin);
  freopen("E1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}