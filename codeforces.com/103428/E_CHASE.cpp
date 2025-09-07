// date: 2025-07-14 14:33:04
// tag: 弱智题。tmd但是小错误一大堆，包括但不限于先算前缀和再排序，搞错变量的含义，搞错dp数组的定义。典型的算期望和找一些数中有多少对数的和小于某个数。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, q;
  std::cin >> n >> k >> q;
  std::vector<int> a(n + 1), s(n + 1);
  int sum = 0, ss = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i] * 2;
    ss += (n - 1) * a[i];
  }
  auto b = a;
  std::vector<double> f(k + 1);
  f[0] = 1.0 * sum / n;
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  auto get = [&](double x) {
    int lcnt = 0, lsum = 0;
    for (int i = 1; i <= n; i++) {
      int r = std::upper_bound(a.begin() + 1, a.end(), x - a[i]) - a.begin() - 1;
      if (r <= i) continue;
      lsum += a[i] * (r - i) + (s[r] - s[i]);
      lcnt += r - i;
    }
    return std::pair{lsum, lcnt};
  };
  // std::cerr << f[0] << '\n';
  // std::cerr << sum << ' ' << ss << '\n';
  for (int i = 1; i <= k; i++) {
    auto [lans, lcnt] = get(f[i - 1]);
    // std::cerr << lans << ' ' << lcnt << ' ' << f[i - 1] << '\n';
    f[i] = 1.0 * (f[i - 1] * lcnt + ss - lans) / (n * (n - 1) / 2);
  }
  std::cout << f[k] << '\n';
  while (q--) {
    int x, y, c;
    std::cin >> x >> y >> c;
    if (c == 0) {
      std::cout << "accept\n";
      continue;
    }
    int s = b[x] + b[y];
    if (std::abs(s - f[c - 1]) < 1e-4) {
      std::cout << "both\n";
    } else if (s > f[c - 1]) {
      std::cout << "accept\n";
    } else {
      std::cout << "reselect\n";
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::cout << std::fixed << std::setprecision(20);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}