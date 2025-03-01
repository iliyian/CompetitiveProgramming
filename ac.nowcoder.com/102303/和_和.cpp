#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::multiset<int> sb, sa;
  int sumb = 0;
  for (int i = 1; i <= m; i++) {
    sb.insert(b[n - i + 1]);
    sumb += b[n - i + 1];
  }
  std::vector<int> mn(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sa.insert(a[i]);
    sum += a[i];
    if (sa.size() > m) {
      sum -= *sa.rbegin();
      sa.erase(--sa.end());
    }
    if (sa.size() == m) {
      mn[i] = sum;
      // std::cerr << i << ' ' << sum << '\n';
      // for (auto i : sa) {
      //   std::cerr << i << ' ';
      // }
      // std::cerr << '\n';
    }
  }
  int ans = LLONG_MAX / 3;
  for (int i = n - m; i >= m; i--) {
    ans = std::min(ans, mn[i] + sumb);
    // std::cout << mn[i] << ' ' << sumb << '\n';
    sumb -= *sb.rbegin();
    sb.erase(--sb.end());
    sb.insert(b[i]);
    sumb += b[i];
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