#include <bits/stdc++.h>
#define int long long

int f[41] {};

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), g(n + 1), h(n + 1), ok(n + 1);
  auto calc = [&](int x) {
    int ans = 0;
    while (x > 1) {
      x = (x + 1) / 2;
      ans++;
    }
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g[i] = calc(a[i]);
    h[i] = calc(a[i] / 2) + 1;
    ok[i] = (g[i] != h[i]);
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << g[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << h[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << 63 - __builtin_clzll(a[i]) << ' ';
  // }
  // std::cerr << '\n';
  for (int i = 1; i <= n; i++) {
    ok[i] += ok[i - 1];
    g[i] += g[i - 1];
    h[i] += h[i - 1];
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int cnt = ok[r] - ok[l - 1];
    int ans = g[r] - g[l - 1];
    cnt = (cnt + 1) / 2;
    std::cout << ans - cnt << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  f[0] = 1;
  for (int i = 1; i <= 40; i++) {
    f[i] = f[i - 1] * 2;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}