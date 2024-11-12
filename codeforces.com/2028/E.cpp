// date: 2024-11-11 19:22:59
// tag: 树形dp，概率dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int x) {
  return qpow(x, mod - 2);
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> d(n + 1, INT_MAX);
  auto dfs1 = [&](auto self, int u, int p) -> void {
    if (g[u].size() == 1 && u != 1) {
      d[u] = 0;
      return;
    }
    int mn = INT_MAX;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        mn = std::min(mn, d[v]);
      }
    }
    d[u] = mn + 1;
  };
  dfs1(dfs1, 1, 0);
  std::vector<int> f(n + 1);
  f[1] = 1;
  auto dfs2 = [&](auto self, int u, int p) -> void {
    if (u != 1) {
      f[u] = d[u] * inv(d[u] + 1) % mod * f[p] % mod;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs2(dfs2, 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cout << f[i] << " \n"[i == n];
  }
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