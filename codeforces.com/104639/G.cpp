// date: 2024-09-11 16:54:41
// tag: 生成树

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

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("G.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::pair<int, int>> op(n);
  for (int i = 1; i <= n - 1; i++) {
    auto &[x, y] = op[i];
    std::cin >> x >> y;
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> id(n + 1), siz(n + 1, 1), pa(n + 1), dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[u] = p;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  auto find = [&](auto self, int x) -> int {return x == id[x] ? x : id[x] = self(self, id[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (dep[x] < dep[y]) std::swap(x, y);
    id[x] = y;
    siz[y] += siz[x];
  };
  int ans = 1;
  std::iota(id.begin() + 1, id.end(), 1);
  for (int i = 1; i <= n - 1; i++) {
    auto [x, y] = op[i];
    std::cin >> x >> y;
    if (!ans) {
      continue;
    }
    x = find(find, x), y = find(find, y);
    if (x == y || find(find, pa[x]) != y && find(find, pa[y]) != x) {
      ans = 0;
    }
    ans = ans * inv(siz[x]) % mod * inv(siz[y]) % mod;
    merge(x, y);
  }
  std::cout << ans << '\n';
  return 0;
}