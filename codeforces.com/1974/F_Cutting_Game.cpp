// date: 2025-03-29 20:00:19
// tag: 转换为贡献之后二分计算某个点最早给哪个东西产生贡献，因为本题关键在于点可能多个贡献。总之是贡献。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, n, m;
  std::cin >> a >> b >> n >> m;
  std::vector<std::pair<int, int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i].first >> v[i].second;
  }
  std::vector<std::pair<char, int>> op(m + 1);
  std::vector<int> u(m + 1), d(m + 1), l(m + 1), r(m + 1);
  u[0] = 0, d[0] = a + 1, l[0] = 0, r[0] = b + 1;
  for (int i = 1; i <= m; i++) {
    std::cin >> op[i].first >> op[i].second;
    u[i] = u[i - 1];
    d[i] = d[i - 1];
    l[i] = l[i - 1];
    r[i] = r[i - 1];
    if (op[i].first == 'U') u[i] += op[i].second;
    if (op[i].first == 'D') d[i] -= op[i].second;
    if (op[i].first == 'L') l[i] += op[i].second;
    if (op[i].first == 'R') r[i] -= op[i].second;
  }
  int lans = 0, rans = 0;
  for (int i = 1; i <= n; i++) {
    auto [x, y] = v[i];
    int L = 0, R = m, ans = -1;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (u[mid] < x && d[mid] > x && l[mid] < y && r[mid] > y) {
        L = mid + 1, ans = mid;
      } else {
        R = mid - 1;
      }
    }
    if (ans != -1 && ans != m) {
      (ans % 2 ? rans : lans)++;
    }
  }
  std::cout << lans << ' ' << rans << '\n';
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