#include <bits/stdc++.h>
#define int long long

const double pi = acos(-1);

void solve() {
  int theta, n;
  std::cin >> theta >> n;
  std::vector<std::pair<double, double>> a;
  // std::cerr << tan(theta * pi / 180) << '\n';
  double tant = tan(theta * pi / 180);
  for (int i = 1; i <= n; i++) {
    int x, h;
    std::cin >> x >> h;
    double r = x + h / tant;
    a.push_back({x, r});
  }
  std::sort(a.begin(), a.end());
  double ans = 0;
  double pr = 0, pl = 0;
  for (auto [l, r] : a) {
    // std::cerr << l << ' ' << r << '\n';
    if (l > pr) {
      ans += pr - pl;
      pl = l, pr = r;
    } else {
      pr = std::max(pr, r);
    }
  }
  ans += pr - pl;
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
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