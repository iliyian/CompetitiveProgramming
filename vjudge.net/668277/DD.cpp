// date: 2024-12-02 00:04:21
// tag: 很妙的将dfs中的节点类型分为子树外节点，当前子树节点和兄弟节点

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  std::vector<int> pre(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    ans += pre[a[u]]; // 当前根节点同当前子树外连边
    int t = pre[a[u]];
    for (int v : g[u]) {
      if (v != p) {
        pre[a[u]] = 1; // 当前子树内目前只能有一个
        self(self, v, u);
      }
    }
    pre[a[u]] = t + 1; // 当前子树外又多了当前这个根节点为一端，此处可以考虑如兄弟节点可以多得一个
  };
  dfs(dfs, 1, 0);
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}