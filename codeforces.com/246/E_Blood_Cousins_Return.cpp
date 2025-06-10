// date: 2025-05-21 19:48:42
// tag: 简直裸的sack

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::string> name(n + 1);
  std::vector<int> pa(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> name[i] >> pa[i];
    g[pa[i]].push_back(i);
  }
  std::vector<int> siz(n + 1), big(n + 1), dfn(n + 1), rnk(n + 1), dep(n + 1);
  int tot = 0;
  auto dfs0 = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    dfn[u] = ++tot;
    dep[u] = dep[p] + 1;
    rnk[tot] = u;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[big[u]]) {
          big[u] = v;
        }
      }
    }
  };
  std::vector<std::set<std::string>> s(n + 1);
  int q;
  std::cin >> q;
  std::vector<std::vector<std::array<int, 2>>> ask(n + 1);
  std::vector<int> ans(q + 1);
  for (int i = 1; i <= q; i++) {
    int v, k;
    std::cin >> v >> k;
    ask[v].push_back({k, i});
  }
  auto add = [&](int x) {
    s[dep[x]].insert(name[x]);
  };
  auto del = [&](int x) {
    s[dep[x]].erase(name[x]);
  };
  auto dfs1 = [&](auto self, int u, int p, bool keep) -> void {
    for (int v : g[u]) {
      if (v != p && v != big[u]) {
        self(self, v, u, false);
      }
    }
    if (big[u]) {
      self(self, big[u], u, true);
    }
    for (int v : g[u]) {
      if (v != p && v != big[u]) {
        for (int i = dfn[v]; i <= dfn[v] + siz[v] - 1; i++) {
          add(rnk[i]);
        }
      }
    }
    add(u);
    for (auto [k, idx] : ask[u]) {
      ans[idx] = (dep[u] + k > n ? 0 : s[dep[u] + k].size());
    }
    if (!keep) {
      for (int i = dfn[u]; i <= dfn[u] + siz[u] - 1; i++) {
        del(rnk[i]);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!pa[i]) {
      dfs0(dfs0, i, 0);
      dfs1(dfs1, i, 0, false);
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
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