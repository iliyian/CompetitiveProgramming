#include <bits/stdc++.h>
#define int long long

struct Node {
  std::array<int, 7> a;
  bool add(int x) {
    for (int i = 6; i >= 0; i--) {
      if (x >> i & 1) {
        if (a[i]) {
          x ^= a[i];
        } else {
          a[i] = x;
          return true;
        }
      }
    }
    return false;
  }
  void merge(const Node &b) {
    for (int i = 6; i >= 0; i--) {
      add(b.a[i]);
    }
  }
};

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1);
  std::vector<Node> f(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool ok = false;
  auto dfs = [&](auto self, int u, int p) -> void {
    if (ok) return;
    f[u].add(a[u]);
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        f[u].merge(f[v]);
      }
    }
    if (!f[u].add(k)) {
      ok = true;
    }
  };
  dfs(dfs, 1, 0);
  std::cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}