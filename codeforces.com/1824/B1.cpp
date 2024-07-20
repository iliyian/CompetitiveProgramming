// date: 2024-07-18 12:58:22
// tag: 概率，树

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int mod = 1e9+7;

int qpow(int a,int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B1.in", "r", stdin);
  freopen("B1.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;
  
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  if (k & 1) {
    std::cout << 1 << '\n';
    return 0;
  }

  std::vector<int> siz(n + 1);
  int ans = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
    ans += siz[u] * (n - siz[u]) % mod;
    ans %= mod;
  };
  dfs(dfs, 1, 0);

  std::cout << (ans * qpow(n * (n - 1) / 2 % mod, mod - 2) + 1) % mod << '\n';

  return 0;
}