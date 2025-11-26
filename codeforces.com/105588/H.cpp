#include <bits/stdc++.h>
#define int long long

using std::numbers::pi;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n + 1);
  std::vector<long double> h(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
    h[i] = std::atan2l(a[i].second, a[i].first);
    // std::cout << h[i] << ' ';     
  }
  std::sort(h.begin() + 1, h.end());
  for (int i = 1; i <= n; i++) {
    h.push_back(h[i] + pi * 2);
  }
  auto check = [&](long double mid) {
    for (int i = 1; i <= n; i++) {
      if (h[i + k] - h[i] > mid) {
        return false;
      }
    }
    return true;
  };
  long double l = 0, r = pi * 2;
  for (int i = 0; i < 100; i++) {
    long double mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid;
  }
  std::cout << std::fixed << std::setprecision(20) << l << '\n';
  // std::cout << '\n';
//   std::ranges::sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
// 
//   });
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int n = 2; n <= 100; n++) {
  //   for (int k = 2; k < n; k++) {
  //     std::vector<int> a(n + 1);
  //     std::ranges::iota(a, 0);
  //     while (a.size() > 2) {
  //       for (int i = 1; i < a.size(); i += k) {
  //         a[i] = 0;
  //       }
  //       std::vector<int> b = {0};
  //       for (int i = 1; i < a.size(); i++) {
  //         if (a[i]) {
  //           b.push_back(a[i]);
  //         }
  //       }
  //       a = b;
  //     }
  //     std::cout << n << ' ' << k << ' ' << a.back() << '\n';
  //   }
  //   std::cout << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}