#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int cur = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    while (cur % n > i % n) {
      ans++;
      cur = cur * 10;
    }
    if (cur % n != i % n) {
      ans++;
      cur += i % n - cur % n;
    }
    std::cerr << cur << '\n';
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