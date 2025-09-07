#include <bits/stdc++.h>
#define int long long

constexpr double eps = 1e-6;
const double pi = acos(-1);

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<std::array<int, 2>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0] >> a[i][1];
  }
  auto cross = [&](int i, int j) {
    return a[i][0] * a[j][1] - a[i][1] * a[j][0];
  };
  auto dot = [&](int i, int j) {
    return a[i][0] * a[j][0] + a[i][1] * a[j][1];
  };
  auto get = [&](int i, int j) {
    return atan2l(cross(i, j), dot(i, j));
  };
  long double s = 0;
  for (int i = 1; i <= n; i++) {
    s += get(i, i % n + 1);
  }
  if (std::abs(s) < eps) {
    std::cout << 2 * pi << '\n';
    return;
  }
  std::vector<double> v(n + 1);
  for (int i = 1; i <= n; i++) {
    v[i] = get(i, i % n + 1);
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::cout << std::fixed << std::setprecision(20);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}