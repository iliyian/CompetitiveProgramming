// date: 2025-04-28 22:30:27
// tag: 比较朴素的dsu+图论+组合数？

#include <bits/stdc++.h>
#define int long long

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

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n * 2; i++) {
    std::cin >> a[i];
  }
  std::vector<std::set<int>> g(n + 1);
  std::set<int> s;
  std::vector<int> in(n + 1), pa(n + 1), siz(n + 1, 1), pa2(n + 1), siz2(n + 1, 1);
  std::iota(pa.begin(), pa.end(), 0);
  std::iota(pa2.begin(), pa2.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  auto find2 = [&](auto self, int x) -> int {return x == pa2[x] ? x : pa2[x] = self(self, pa2[x]);};
  auto merge2 = [&](int x, int y) -> bool {
    x = find2(find2, x), y = find2(find2, y);
    if (x == y) return false;
    if (siz2[x] > siz2[y]) std::swap(x, y);
    pa2[x] = y;
    siz2[y] += siz2[x];
    return true;
  };
  for (int i = 1; i <= n * 2; i++) {
    for (auto j : s) {
      if (j != a[i]) {  
        g[j].insert(a[i]);
        merge2(j, a[i]);
        // g[i].insert(j); // 反向图
      }
    }
    if (s.count(a[i])) s.erase(a[i]);
    else s.insert(a[i]);
  }
  std::vector<std::vector<int>> g2(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (g[i].count(j) && g[j].count(i)) {
        merge(i, j);
        g[i].erase(j);
        g[j].erase(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j : g[i]) {
      if (find(find, i) == find(find, j)) continue;
      g2[find(find, i)].push_back(find(find, j));
      in[find(find, j)]++;
    }
  }
  // int t = 1, tt = 0;
  // while (t != 687865726) {
  //   t = t * 2 % mod;
  //   tt++;
  // }
  // std::cout << tt << '\n';
  int ans1 = 0, ans2 = 1;
  for (int i = 1; i <= n; i++) {
    if (i == pa2[i]) ans1++;
    if (i == pa[i]) {
      if (in[i] == 0) {
        // std::cerr << i << ' ' << siz[i] << '\n';
        ans2 *= siz[i] * 2;
        ans2 %= mod;
        // std::cerr << ans2 << '\n';
      }
    }
  }
  std::cout << ans1 << ' ' << ans2 << '\n';
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