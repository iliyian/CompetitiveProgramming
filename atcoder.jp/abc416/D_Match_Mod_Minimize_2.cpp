#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    ans += a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    ans += b[i];
  }
  std::ranges::sort(a);
  std::ranges::sort(b);
  int pre = 0;
  for (int i = n - 1; i >= 0; i--) {
    int p = std::lower_bound(b.begin() + pre, b.end(), m - a[i]) - b.begin();
    if (p == n) {
      break;
    }
    // std::cerr << a[i] << ' ' << b[]
    ans -= m;
    pre = p + 1;
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