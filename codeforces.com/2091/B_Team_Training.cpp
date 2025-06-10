#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  int cnt = 0, mn = LLONG_MAX, ans = 0;
  for (int i = 1; i <= n; i++) {
    mn = std::min(mn, a[i]);
    cnt++;
    if (mn * cnt >= k) {
      mn = LLONG_MAX, cnt = 0;
      ans++;
      // std::cerr << i << '\n';
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