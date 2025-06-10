// date: 2025-05-21 19:33:52
// tag: 树上启发式合并。还是跟子树相关的。感觉都是一个板子，就是算贡献的部分不同罢了。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    std::cin >> p;
    g[p].push_back(i);
  }
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::vector<int> siz(n + 1), dfn(n + 1), rnk(n + 1), son(n + 1), dep(n + 1);
  std::vector<int> cnt(n + 1);
  int tot = 0;
  auto dfs0 = [&](auto self, int u) -> void {
    siz[u] = 1;
    dfn[u] = ++tot;
    rnk[tot] = u;
    for (int v : g[u]) {
      dep[v] = dep[u] + 1;
      self(self, v);
      siz[u] += siz[v];
      if (siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
  };
  std::vector<std::vector<std::array<int, 2>>> ask(n + 1);
  std::vector<int> ans(q + 1);
  auto add = [&](int x) {
    cnt[dep[x]] ^= 1ll << (str[x] - 'a');
  };
  auto dfs1 = [&](auto self, int u, bool keep) -> void {
    for (int v : g[u]) {
      if (v != son[u]) {
        self(self, v, false);
      }
    }
    if (son[u]) {
      self(self, son[u], true);
    }
    for (int v : g[u]) {
      if (v != son[u]) {
        for (int i = dfn[v]; i <= dfn[v] + siz[v] - 1; i++) {
          add(rnk[i]);
        }
      }
    }
    add(u);
    for (auto [h, idx] : ask[u]) {
      ans[idx] = __builtin_popcountll(cnt[h]) <= 1;
    }
    if (!keep) {
      for (int i = dfn[u]; i <= dfn[u] + siz[u] - 1; i++) {
        add(rnk[i]);
      }
    }
  };
  for (int i = 1; i <= q; i++) {
    int v, h;
    std::cin >> v >> h;
    ask[v].push_back({h, i});
  }
  dep[1] = 1;
  dfs0(dfs0, 1);
  dfs1(dfs1, 1, false);
  for (int i = 1; i <= q; i++) {
    std::cout << (ans[i] ? "Yes" : "No") << '\n';
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