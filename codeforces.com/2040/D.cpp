// date: 2024-12-09 19:59:37
// tag: 大胆猜结论的玄学题，树上贪心构造，质数，dfs，出题人表示自己也hack不了很多证明不了的解法

#include <bits/stdc++.h>
#define int long long

constexpr int N = 6e5;

std::vector<int> pri, vis(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> pa(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> ans(n + 1);
  int cur = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    ans[u] = ++cur;
    while (!vis[std::abs(ans[u] - ans[pa[u]])]) ans[u]++, cur++;
    for (int v : g[u]) {
      if (v != p) {
        pa[v] = u;
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  vis[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = 1;
      if (i % p == 0) break;
    }
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
