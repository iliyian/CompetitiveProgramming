#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> a(n);
  int tot = 0;
  for (auto &[x, y, id] : a) {
    std::cin >> x >> y;
    id = ++tot;
  }
  std::ranges::sort(a, [&](auto x, auto y) {
    return x[0] < y[0];
  });
  std::sort(a.begin(), a.begin() + n / 2, [&](auto x, auto y) {
    return x[1] < y[1];
  });
  std::sort(a.begin() + n / 2, a.end(), [&](auto x, auto y) {
    return x[1] < y[1];
  });
  // if (n == 2) {
  //   std::cout << 1 << ' ' << 2 << '\n';
  //   return;
  // }
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    std::cout << a[i][2] << ' ' << a[n - i - 1][2] << '\n';
    // ans += std::abs(a[i][0] - a[n - i - 1][0]) + std::abs(a[i][1] - a[n - i - 1][1]);
  }
  // std::cerr << ans << '\n';
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