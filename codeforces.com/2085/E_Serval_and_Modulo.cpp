#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  int asum = 0, bsum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    asum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    bsum += b[i];
  }
  std::sort(b.begin() + 1, b.end());
  int d = asum - bsum;
  if (d < 0) {
    std::cout << -1 << '\n';
    return;
  }
  if (d == 0) {
    std::sort(a.begin() + 1, a.end());
    if (a == b) {
      std::cout << (int)1e7 << '\n';
    } else {
      std::cout << -1 << '\n';
    }
    return;
  }
  auto check = [&](int x) {
    auto c = a;
    for (auto &j : c) {
      j %= x;
    }
    std::sort(c.begin() + 1, c.end());
    return c == b;
  };
  for (int i = 1; i * i <= d; i++) {
    if (d % i == 0) {
      if (check(i)) {
        std::cout << i << '\n';
        return;
      }
      if (i * i != d && check(d / i)) {
        std::cout << d / i << '\n';
        return;
      }
    }
  }
  std::cout << -1 << '\n';
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