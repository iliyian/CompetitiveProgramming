#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v, x, y;
    std::cin >> u >> v >> x >> y;
    if (x > y) {
      g[v].push_back(u);
      in[u]++;
    } else {
      g[u].push_back(v);
      in[v]++;
    }
  }
  std::queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      q.push(i);
    }
  }
  std::vector<int> ans(n + 1);
  int tot = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ans[u] = ++tot;
    for (int v : g[u]) {
      if (!--in[v]) {
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}