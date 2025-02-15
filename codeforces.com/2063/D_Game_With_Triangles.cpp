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
  std::sort(a.begin() + 1, a.end());
  std::sort(b.begin() + 1, b.end());
  int x = 0, y = 0;
  auto check = [&](int x, int y) {
    return 2 * x + y <= n && 2 * y + x <= m;
  };
  int k = (n + m) / 3;
  std::vector<int> ans(k + 1);
  std::vector<int> c(n + 1), d(m + 1);
  for (int i = 1; i < n - i + 1; i++) {
    c[i] = a[n - i + 1] - a[i];
  }
  for (int i = 1; i < m - i + 1; i++) {
    d[i] = b[m - i + 1] - b[i];
  }
  int sum = 0;
  while (true) {
    while (x && !check(x, y + 1)) sum -= c[x--];
    while (y && !check(x + 1, y)) sum -= d[y--];
    if (!check(x, y)) break;
    if (x + 1 <= n / 2 && y + 1 <= m / 2) {
      if (c[x + 1] > d[y + 1]) {
        sum += c[++x];
      } else {
        sum += d[++y];
      }
      continue;
    }
    if (x + 1 <= n / 2) sum += c[++x];
    else if (y + 1 <= m / 2) sum += d[++y];
    else assert(false);
  }
  std::cout << k << '\n';
  for (int i = 1; i <= k; i++) {
    std::cout << ans[i] << " ";
  }
  std::cout << '\n';
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