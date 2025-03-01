#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n * 2; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[n * 2 - i + 1] - a[i];
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