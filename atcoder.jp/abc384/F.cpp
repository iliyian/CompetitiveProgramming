#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::map<int, int>> mp(26);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int prv = (1 << 25) - (a[i] % (1 << 25)), cur;
    ans += mp[25][prv];
    for (int j = 24; j >= 0; j--) {
      cur = (1 << j) - (a[i] % (1 << j));
      ans += mp[j][cur] - mp[j][prv];
      prv = cur;
    }
    for (int j = 0; j <= 25; j++) {
      int t = a[i] % (1 << j);
      mp[j][t] += a[i];
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
