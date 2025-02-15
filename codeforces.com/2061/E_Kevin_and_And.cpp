#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n), b(m);
  std::vector<std::vector<int>> f(n, std::vector<int>(m + 1, INT_MAX));
  int sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    f[i][0] = a[i];
    sum += a[i];
  }
  int ini = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
    ini |= b[i];
  }
  for (int S = 1; S < (1 << m); S++) {
    int j = ini, cnt = __builtin_popcountll(S);
    for (int i = 0; i < m; i++) {
      if (S >> i & 1) {
        // if ((j & b[i]) == 0) {
        //   std::cout << b[i] << ' ' << j << '\n';
        // }
        j &= b[i];
      }
    }
    for (int i = 0; i < n; i++) {
      // if (i == 5 && (a[i] & j) == 0) {
      //   std::cout << a[i] << ' ' << j << ' ' << (a[i] & j) << ' ' << S << '\n';
      // }
      f[i][cnt] = std::min(f[i][cnt], a[i] & j);
    }
  }
  std::multiset<int> s;
  // std::cout << sum << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = m; j > 0; j--) {
      f[i][j] -= f[i][j - 1];
    }
    // std::cout << a[i] << ' ';
    for (int j = 1; j <= std::min(k, m); j++) {
      s.insert(f[i][j]);
      // std::cout << f[i][j] << ' ';
      if (s.size() > k) {
        s.erase(--s.end());
        // assert(s.size() == k);
      }
    }
    // std::cout << '\n';
  }
  // std::cout << s.size() << '\n';
  for (auto i : s) {
    // std::cout << i << ' ';
    sum += i;
  }
  std::cout << sum << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}