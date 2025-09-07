#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, A, B, C;
  std::cin >> n >> A >> B >> C;
  // std::vector<int> f(n * 4);
  int U = (1ll << 30) - 1;
  // auto getf = [&](int x) {
  //   if (x == -3) {
  //     return A & U;
  //   }
  //   if (x == -2) {
  //     return B & U;
  //   }
  //   if (x == -1) {
  //     return C & U;
  //   }
    // return f[x];
  // };
  int f[4] = {0, A & U, B & U, C & U};
  auto getf = [&](int x) {
    return f[(x % 4 + 4) % 4];
  };
  int h, g;
  // std::vector<int> g(n * 4), h(n * 4), l(n), r(n), d(n);
  int ans = 0;
  // std::vector<int> l(n), r(n), d(n);
  for (int i = 0; i < n * 4; i++) {
    g = getf(i - 3) ^ ((getf(i - 3) << 16) & U);
    h = g ^ (g >> 5);
    f[i % 4] = h ^ ((2 * h) & U) ^ getf(i - 2) ^ getf(i - 1);
    if (i < n) {
      ans += (f[i % 4] % (n - i) != 0);
      ans %= 2;
    }
    if (i == n) {
      std::cout << ans;
    }
    if (i >= n && (i - n) % 3 == 2 && i <= 4 * n - 4) {
      int d = getf(i) % n + 1;
      int l = std::min(getf(i - 2) % n, getf(i - 1) % n);
      int r = std::max(getf(i - 2) % n, getf(i - 1) % n);
      // std::cerr << "(l,r,d)=" << l << ' ' << r << ' ' << d << '\n';
      if ((r - l + 1) % 2 == 0 && d % 2 == 1) {
        ans ^= 1;
      }
      std::cout << ans;
    }
    // std::cerr << f[i % 4] << ' ';
  }
  std::cout << '\n';
  // std::cerr << '\n';
  // int ans = cnt % 2;
  // int ans = cnt % 2;
  // for (int i = 0; i < n * 4; i++) {
  //   g[i] = getf(i - 3) ^ ((getf(i - 3) << 16) & U);
  //   h[i] = g[i] ^ (g[i] >> 5);
  //   f[i] = h[i] ^ ((2 * h[i]) & U) ^ getf(i - 2) ^ getf(i - 1);
  // }
  // for (int i = 1; i < n; i++) {
  //   l[i] = std::min(f[n + 3 * i - 3] % n, f[n + 3 * i - 2] % n);
  //   r[i] = std::max(f[n + 3 * i - 3] % n, f[n + 3 * i - 2] % n);
  //   d[i] = (f[n + 3 * i - 1]) % n + 1;
  // }
  // for (int i = 0; i < n * 4; i++) {
  //   std::cout << f[i] << ' ';
  // }
  // std::cout << '\n';
  // std::vector<int> a(n);
  // std::iota(a.begin(), a.end(), 0);
  // for (int i = 0; i < n; i++) {
  //   // std::cerr << "swap(" << i << ',' << i + f[i] % (n - i) << ")\n";
  //   std::swap(a[i], a[i + f[i] % (n - i)]);
  // }
  // std::cout << "p[i]=";
  // for (int i = 0; i < n; i++) {
  //   std::cout << a[i] << ' ';
  // }
  // std::cout << '\n';
  // std::cout << "l[i] r[i] d[i]\n";
  // for (int i = 1; i < n; i++) {
  //   std::cout << l[i] << ' ' << r[i] << ' ' << d[i] << '\n';
  // }
  // std::vector<int> tr(n + 1);
  // auto add = [&](int x, int c) {
  //   x++;
  //   for (int i = x; i <= n; i += i & -i) tr[i] += c;
  // };
  // auto query = [&](int x) -> int {
  //   int ans = 0;
  //   x++;
  //   for (int i = x; i > 0; i -= i & -i) ans += tr[i];
  //   return ans;
  // };
  // int ans = 0;
  // for (int i = 0; i < n; i++) {
  //   ans += i - query(a[i]);
  //   add(a[i], 1);
  // }
  // std::cout << "inians=";
  // std::cout << ans << '\n';
  // int real = n % 2;
  // ans %= 2;
  // std::cerr << "check:" << cnt % 2 << ' ' << ans % 2 << '\n';
  // std::cerr << real << ' ' << ans << '\n';
  // std::cout << ans;
  // for (int i = 1; i < n; i++) {
  //   int len = r[i] - l[i] + 1;
  //   if (len % 2 == 0 && d[i] % 2 == 1) {
  //     ans ^= 1;
  //   }
  //   std::cout << ans;
  // }
  // std::cout << '\n';
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