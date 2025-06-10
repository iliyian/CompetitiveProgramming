#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  auto b = a;
  std::sort(b.begin() + 1, b.end());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    auto l = std::lower_bound(b.begin() + 1, b.end(), sum - a[i] - y) - b.begin();
    auto r = std::upper_bound(b.begin() + 1, b.end(), sum - a[i] - x) - b.begin() - 1;
    if (l < b.size() && r >= 0) {
      int res = r - l + 1;
      if (b[l] <= a[i] && a[i] <= b[r]) {
        res--;
      }
      ans += res;
    }
  }
  std::cout << ans / 2 << '\n';
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