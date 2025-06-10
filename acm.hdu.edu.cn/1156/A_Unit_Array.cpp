#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int s = 0, m = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s += a[i], m *= a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s >= 0 && m == 1) {
      std::cout << ans << '\n';
      return;
    }
    if (a[i] == -1) {
      s += 2, m *= -1;
      ans++;
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