// date: 2025-03-18 22:51:37
// tag: 神奇数学题，首先推导最优解可行性，然后根据函数的上凸性进行整数三分，顺便这题三分写法很好

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  int x = n, y = m, k = 0;
  while (x && y) {
    if (x < y) std::swap(x, y);
    if (x >= 2 && y >= 1) x -= 2, y--, k++;
    else break;
  }
  std::sort(a.begin() + 1, a.end());
  std::sort(b.begin() + 1, b.end());
  std::vector<int> c(n + 1), d(m + 1);
  for (int i = 1; i * 2 <= n; i++) {
    c[i] = c[i - 1] + a[n - i + 1] - a[i];
  }
  for (int i = 1; i * 2 <= m; i++) {
    d[i] = d[i - 1] + b[m - i + 1] - b[i];
  }
  auto get = [&](int x, int s) -> int {
    int y = s - x;
    if (!(x * 2 + y <= n && y * 2 + x <= m)) {
      // std::cerr << n << ' ' << m << ' ' << x << ' ' << y << ' ' << s << '\n';
    }
    return c[x] + d[y];
  };
  std::cout << k << '\n';
  for (int i = 1; i <= k; i++) {
    int l = std::min(std::max(0ll, 2 * i - m), i), r = std::max(0ll, std::min(i, n - i)), ans = -1;
    assert(l <= r);
    // std::cerr << n << ' ' << m << ' ' << l << ' ' << r << ' ' << i << '\n';
    // continue;
    while (l < r) {
      int mid = (l + r) / 2;
      if (get(mid, i) < get(mid + 1, i)) l = mid + 1;
      else r = mid;
    }
    int mx = std::max(get(l, i), get(r, i));
    std::cout << mx << ' ';
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