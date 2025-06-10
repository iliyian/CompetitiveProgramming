// date: 2025-05-21 18:52:33
// tag: 神奇的树上启发式合并？树上静态链合并？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> siz(n + 1), big(n + 1), dfn(n + 1), rnk(n + 1);
  int tot = 0;
  auto dfs0 = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    dfn[u] = ++tot;
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
  std::vector<int> cnt(n + 1), sum(n + 1), ans(n + 1);
  int mx = 0;
  auto add = [&](int x) {
    sum[cnt[c[x]]] -= c[x];
    cnt[c[x]]++;
    sum[cnt[c[x]]] += c[x];
    if (cnt[c[x]] >= mx) {
      mx = cnt[c[x]];
    }
  };
  auto del = [&](int x) {
    sum[cnt[c[x]]] -= c[x];
    cnt[c[x]]--;
    sum[cnt[c[x]]] += c[x];
    while (mx >= 1 && !cnt[mx]) mx--;
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
    ans[u] = sum[mx];
    if (!keep) {
      for (int i = dfn[u]; i <= dfn[u] + siz[u] - 1; i++) {
        del(rnk[i]);
      }
    }
  };
  dfs0(dfs0, 1, 0);
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << big[i] << " \n"[i == n];
  // }
  dfs1(dfs1, 1, 0, false);
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
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