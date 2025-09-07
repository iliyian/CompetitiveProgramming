#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, len;
  std::cin >> n >> len;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto check = [&](double mid) -> bool {
    std::vector<double> s(n + 1);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + a[i] - mid;
    }
    double mn = 0;
    for (int i = len; i <= n; i++) {
      if (s[i] >= mn) {
        return true;
      }
      mn = std::min(mn, s[i - len + 1]);
    }
    return false;
  };
  double l = -3e9, r = 3e9, ans;
  while (r - l >= 1e-6) {
    double mid = (l + r) / 2;
    if (check(mid)) l = mid, ans = mid;
    else r = mid;
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
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