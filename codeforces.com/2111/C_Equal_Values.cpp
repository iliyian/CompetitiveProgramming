#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int px = -1, ans = LLONG_MAX, cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ans = std::min(ans, x * (n - 1));
    if (x == px) {
      cnt++;
      ans = std::min(ans, x * (n - cnt));
    } else {
      cnt = 1;
    }
    px = x;
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