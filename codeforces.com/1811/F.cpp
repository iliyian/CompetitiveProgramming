// date: 2024-07-14 22:49:55
// tag: 构造，模拟

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> in(n + 1), pa(n + 1);
  iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
    pa[find(find, x)] = find(find, y);
  }

  bool f = false;
  for (int i = 1; i <= n; i++) {
    if (pa[i] == i) {
      if (f) {
        std::cout << "NO\n";
        return;
      }
      f = true;
    }
  }

  int t = sqrt(n);
  if (t * t != n) {
    std::cout << "NO\n";
    return;
  }

  int in4 = 0;
  for (int i = 1; i <= n; i++) {
    in4 += (in[i] == 4);
    if (in[i] != 4 && in[i] != 2) {
      std::cout << "NO\n";
      return;
    }
  }
  if (in4 != t) {
    std::cout << "NO\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (in[i] == 4) {
      int cnt2 = 0, cnt4 = 0;
      for (int v : g[i]) {
        cnt2 += in[v] == 2;
        cnt4 += in[v] == 4;
      }
      if (cnt2 != 2 || cnt4 != 2) {
        std::cout << "NO\n";
        return;
      }
    }
  }

  std::vector<int> siz(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p && in[v] == 2 && !siz[v]) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };

  for (int u = 1; u <= n; u++) {
    if (in[u] == 4) {
      bool f = false;
      for (int i : g[u]) {
        if (in[i] == 2 && siz[i] == 0) {
          f = true;
          dfs(dfs, i, 0);
          if (siz[i] != t - 1) {
            std::cout << "NO\n";
            return;
          }
        }
      }
      if (!f) {
        std::cout << "NO\n";
        return;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!siz[i] && in[i] == 2) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}