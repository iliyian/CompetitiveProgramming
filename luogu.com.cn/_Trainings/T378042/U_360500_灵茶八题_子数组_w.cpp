#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  constexpr int N = 1ll << 25;
  std::vector<int> d(N + 1);
  auto add = [&](int x, int c) {
    x++;
    if (x <= 0) return;
    for (int i = x; i <= N; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    x++;
    if (x > N) x = N;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  int ans = 0;
  int mask = (1 << 25) - 1;
  for (int j = 24; j >= 0; j--) {
    add(0, 1);
    for (int i = 1; i <= n; i++) {
      int v = (a[i] & mask) + (1 << (j + 1));
      auto x = query(v - (1 << j)) - query(v - (1 << (j + 1)));
      // if (j == 0 && i == 2) {
      //   std::cerr << a[i] - (1 << j) << ' ' << a[i] - (1 << (j + 1)) << ' ' << a[i] << '\n';
      // }
      if (x > 0) {
        ans ^= (x % 2) << j;
        // if (j == 0) {
          std::cerr << x << ' ' << i << ' ' << v << ' ' << j << ' ' << 1 << '\n';
        // }
      }
      auto y = query(v - (1 << j) - (1 << (j + 1))) - query(v - (1 << (j + 2)));
      if (y > 0) {
        ans ^= (y % 2) << j;
        // if (j == 0) {
          std::cerr << y << ' ' << i << ' ' << v << ' ' << j << ' ' << 2 << '\n';
        // }
      }
      add(a[i], 1);
    }
    for (int i = 1; i <= n; i++) {
      add(a[i], -1);
    }
    add(0, -1);
    mask ^= 1 << j;
  }
  std::cout << ans << '\n';
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