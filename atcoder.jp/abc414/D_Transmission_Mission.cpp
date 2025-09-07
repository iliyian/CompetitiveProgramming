#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());
  int ans = a.back() - a.front();
  n = a.size();
  for (int i = n - 1; i >= 1; i--) {
    a[i] = a[i] - a[i - 1];
  }
  // for (int i = 1; i < n; i++) {
  //   std::cerr << a[i] << " "[i == n - 1];
  // }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  if (n <= m) {
    std::cout << 0 << '\n';
    return;
  }
  for (int i = 1; i < m; i++) {
    ans -= a[i];
  }
  std::cout << ans << '\n';
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