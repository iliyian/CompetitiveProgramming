#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2), l(n + 1), r(n + 2);
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    l[i] = r[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    l[i] = std::max(l[i], l[i - 1]);
  }
  for (int i = n - 1; i >= 1; i--) {
    r[i] = std::max(r[i], r[i + 1]);
  }
  int ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    ans += std::min(l[i], r[i]) - a[i];
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