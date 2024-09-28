#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int ans = 0, cur = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x >= k) {
      cur += x;
    }
    if (x == 0 && cur) {
      cur--;
      ans++;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("A.in", "r", stdin);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}