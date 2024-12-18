// date: 2024-12-18 17:47:01
// tag: 好吧，基环树森林找环，直接用scc是个好主意

// date: 2024-12-16 22:55:13
// tag: 基环树森林dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> isloop(n + 1), in(n + 1);
  std::vector<std::vector<int>> g(n + 1), h(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g[a[i]].push_back(i);
    // h[i].push_back(a[i]);
    // h[a[i]].push_back(i);
  }
  std::vector<int> dfn(n + 1), low(n + 1), ins(n + 1);
  int dfncnt = 0;
  std::stack<int> s;
  int scccnt = 0;
  auto dfs = [&](auto self, int u) -> void {
    dfn[u] = low[u] = ++dfncnt;
    s.push(u);
    ins[u] = 1;
    for (auto v : g[u]) {
      if (!dfn[v]) {
        self(self, v);
        low[u] = std::min(low[u], low[v]);
      } else if (ins[v]) {
        // greedy
        low[u] = std::min(low[u], dfn[v]);
      }
    }
    if (low[u] == dfn[u]) {
      std::vector<int> cur;
      while (true) {
        int x = s.top(); s.pop();
        ins[x] = false;
        cur.push_back(x);
        if (x == u) break;
      }
      if (cur.size() >= 2) {
        for (auto i : cur) {
          isloop[i] = 1;
        }
      }
      cur.clear();
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) { // 基环树往往以基环树森林的形式出现
      dfs(dfs, i);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << isloop[i] << " \n"[i == n];
  // }
  std::vector<int> siz(n + 1);
  int maxsiz = 0;
  auto dfs2 = [&](auto self, int u) -> void {
    if (siz[u]) return;
    siz[u] = 1;
    // std::cout << u << '\n';
    for (int v : g[u]) {
      if (!isloop[v]) {
        self(self, v);
        siz[u] += siz[v];
      }
    }
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (isloop[i]) {
      for (int v : g[i]) {
        if (isloop[v]) continue;
        dfs2(dfs2, v);
        ans = std::max(ans, siz[v]);
      }
    }
  }
  std::cout << ans + 2 << '\n';
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