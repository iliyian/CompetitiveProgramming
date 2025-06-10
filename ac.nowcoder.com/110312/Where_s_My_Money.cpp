#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, p;
  std::cin >> n >> m >> p;
  // std::vector<int> a(n + 1), b(m + 1), c(p + 1);
  int a = 0, b = 0, c = 0;
  for (int i = 1; i <= n; i++) {
    double x;
    std::cin >> x;
    a += x * 100;
  }
  for (int i = 1; i <= m; i++) {
    double x;
    std::cin >> x;
    b += x * 100;
  }
  for (int i = 1; i <= p; i++) {
    double x;
    std::cin >> x;
    c += x * 100;
  }
  int x = (a + b + c) / 3;
  // std::cerr << x << ' ' << a << ' ' << b << ' ' << c << '\n';
  std::vector<int> ans(6);
  if (a >= x && b <= x && c <= x) {
    ans[4] = x - c, ans[2] = x - b;
  } else if (b >= x && a <= x && c <= x) {
    ans[0] = x - a, ans[5] = x - c;
  } else if (c >= x && a <= x && b <= x) {
    ans[1] = x - a, ans[3] = x - b;
  } else if (a <= x && b >= x && c >= x) {
    ans[0] = b - x, ans[1] = c - x;
  } else if (b <= x && a >= x && c >= x) {
    ans[2] = a - x, ans[3] = c - x;
  } else if (c <= x && a >= x && b >= x) {
    ans[4] = a - x, ans[5] = b - x;
  }
  for (int i = 0; i < 6; i++) {
    std::cout << std::max(0.0, 0.01 * ans[i]) << ' ';
  }
  std::cout << '\n';
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