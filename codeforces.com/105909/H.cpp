// date: 2025-05-24 21:20:50
// tag: 没见过这么朴素的换根dp，随便推一下式子就可以了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> d(n + 1), sd(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    d[x]++, d[y]++;
  }
  std::vector<int> ans(n + 1), dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    sd[u] = d[u];
    dep[u] = dep[p] + 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        sd[u] += sd[v];
      }
    }
  };
  dfs(dfs, 1, 0);
  for (int i = 1; i <= n; i++) {
    ans[1] += (dep[i] - 1) * d[i];
  }
  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        ans[v] = ans[u] - sd[v] + 2 * (n - 1) - sd[v];
        self(self, v, u);
      }
    }
  };
  dfs2(dfs2, 1, 0);
  int mn = LLONG_MAX, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] < mn) {
      cnt = 1;
      mn = ans[i];
    } else if (ans[i] == mn) {
      cnt++;
    }
  }
  std::cout << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    if (ans[i] == mn) {
      std::cout << i << ' ';
    }
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