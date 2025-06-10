// date: 2025-04-30 16:39:36
// tag: 神秘模拟题，不知道什么意义

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> pa(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> son(n + 1), siz(n + 1);
  std::vector<std::set<std::pair<int, int>>> ch(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        pa[v] = u;
        siz[u] += siz[v];
        a[u] += a[v];
        ch[u].insert({-siz[v], v});
        if (siz[v] > siz[son[u]] || siz[v] == siz[son[u]] && v < son[u]) {
          son[u] = v;
        }
      }
    }
  };
  dfs(dfs, 1, 0);
  for (int _ = 1; _ <= q; _++) {
    int op, x;
    std::cin >> op >> x;
    if (op == 1) {
      // if (a[x] == 145489303) {
      //   std::cerr << x << '\n';
      // }
      std::cout << a[x] << '\n';
    } else {
      int s = son[x];
      if (!s) continue;
      int t = a[x];
      a[x] -= a[son[x]];
      a[son[x]] = t;
      t = siz[x];
      siz[x] -= siz[son[x]];

      ch[x].erase({-siz[son[x]], son[x]});
      siz[son[x]] = t;
      int p = pa[x];
      pa[x] = son[x];
      pa[son[x]] = p;
      if (!ch[x].empty()) {
        son[x] = ch[x].begin()->second;
      } else {
        son[x] = 0;
      }

      ch[s].insert({-siz[x], x});
      if (!ch[s].empty()) {
        son[s] = ch[s].begin()->second;
      } else {
        son[s] = 0;
      }

      ch[p].erase({-siz[s], x});
      ch[p].insert({-siz[s], s});
      son[p] = ch[p].begin()->second;
    }
  }
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