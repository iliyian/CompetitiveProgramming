#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> siz(n + 1);
  std::vector<int> f(n + 1); // 此时根为 1
  std::vector<int> ans(n + 1);
  auto dfs1 = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  dfs1(dfs1, 1, 0);
  auto dfs2 = [&](auto self, int u, int p) -> void {
    std::vector<int> a = {n - siz[u]};
    for (int v : g[u]) {
      if (v != p) {
        f[u] += (n - siz[v]) * siz[v];
        self(self, v, u);
        a.push_back(siz[v]);
      }
    }
    int sizp = n - siz[u], sum = 0, t = 0;
    f[u] += (n - sizp) * sizp;
    for (int i = 0; i < a.size(); i++) {
      sum += a[i] * t;
      t += a[i];
    }
    f[u] += sum;
    for (int i = 0; i < a.size(); i++) {
      f[u] += (sum - (a[i] * (t - a[i]))) * a[i];
    }
  };
  dfs2(dfs2, 1, 0);
  for (int i = 1; i <= n; i++) {
    f[i] += n;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << f[i] << ' ';
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