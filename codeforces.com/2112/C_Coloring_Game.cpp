#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int l = a[n] - a[i] - a[j], r = a[i] + a[j];
      auto p = std::upper_bound(a.begin() + j + 1, a.end(), l);
      auto q = std::lower_bound(a.begin() + j + 1, a.end(), r) - 1;
      if (p != a.end() && q != a.end() && q >= p) {
        ans += q - p + 1;
      }
    }
  }
  std::cout << ans << '\n';
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