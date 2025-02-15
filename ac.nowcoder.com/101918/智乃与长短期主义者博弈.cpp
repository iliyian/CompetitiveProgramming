#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<std::array<int, 2>>> f(n + 1, std::vector<std::array<int, 2>>(n + 1, {LLONG_MIN / 3}));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  auto get = [&](int l, int r) {
    return a[r] - a[l - 1];
  };
  for (int i = 1; i <= n; i++) {
    f[i][i] = {get(i, i), get(i, i)};
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      f[l][r][0] = (get(l, l) >= get(r, r) ? get(l + 1, r) - f[l + 1][r][1] + get(l, l) : get(l, r - 1) - f[l][r - 1][1] + get(r, r));
      f[l][r][1] = std::max(get(l + 1, r) - f[l + 1][r][0] + get(l, l), get(l, r - 1) - f[l][r - 1][0] + get(r, r));
      // std::cerr << l << ' ' << r << ' ' << f[l][r][0] << ' ' << f[l][r][1] << '\n';
      // assert(f[l][r][0] + f[l][r][1] == get(l, r));
    }
  }
  std::cout << f[1][n][0] << ' ' << get(1, n) - f[1][n][0] << '\n';
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