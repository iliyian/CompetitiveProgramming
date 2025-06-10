#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s;
  std::vector<std::vector<int>> g(n + 1), h(n + 1);
  std::vector<int> ind(n + 1), outd(n + 1);
  std::vector<std::pair<int, int>> e;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> s >> y;
    if (s == "->") {
      g[x].push_back(y);
      h[y].push_back(x);
      ind[y]++, outd[x]++;
    } else {
      e.push_back({x, y});
    }
  }
  std::vector<int> in(n + 1), out(n + 1);
  auto dfs = [&](auto self, int u) -> void {
    for (int v : g[u]) {
      in[v] = std::max(in[v], in[u] + 1);
      self(self, v);
    }
  };
  auto dfs2 = [&](auto self, int u) -> void {
    for (int v : h[u]) {
      out[v] = std::max(out[v], out[u] + 1);
      self(self, v);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!ind[i]) {
      dfs(dfs, i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!outd[i]) {
      dfs2(dfs2, i);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << in[i] << " \n"[i == n];
  // }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << out[i] << " \n"[i == n];
  // }
  int ans = 0;
  for (auto [x, y] : e) {
    ans = std::max({ans, in[x] + out[y] + 1, in[y] + out[x] + 1});
  }
  std::cout << ans << '\n';
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