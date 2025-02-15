// date: 2025-01-27 22:08:54
// tag: 拓扑排序，自动机思想？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  // set true
  // set false
  // unset true
  // unset false
  std::vector<int> a(n + 1);
  int _s = -1, _t = -1;
  for (int i = 1; i <= n; i++) {
    std::string x, y;
    std::cin >> x >> y;
    a[i] = ((x == "set") << 1) | (y == "true");
    if (a[i] == 3) _s = i;
    if (a[i] == 1) _t = i;
  }
  std::vector<int> in(n + 1), ans, vis(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    in[y]++;
  }
  if (_s == -1 && _t != -1) {
    std::cout << -1 << '\n';
    return;
  }
  std::queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i] && a[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    ans.push_back(u);
    for (int v : g[u]) {
      if (!--in[v] && a[v] == 0) {
        q.push(v);
      }
    }
  }
  if (_s != -1 && !in[_s]) {
    q.push(_s);
    for (int i = 1; i <= n; i++) {
      if (!in[i] && a[i] == 2) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      ans.push_back(u);
      for (int v : g[u]) {
        if (!--in[v] && a[v] == 2) {
          q.push(v);
        }
      }
    }
    if (_t != -1 && !in[_t]) {
      q.push(_t);
      for (int i = 1; i <= n; i++) {
        if (!in[i] && a[i] == 0) {
          q.push(i);
        }
      }
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans.push_back(u);
        for (int v : g[u]) {
          if (!--in[v] && a[v] == 0) {
            q.push(v);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (in[i]) {
      std::cout << -1 << '\n';
      std::cerr << "3\n";
      return;
    }
  }
  if (ans.size() != n) {
    std::cout << "-1\n";
    return;
  }
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}