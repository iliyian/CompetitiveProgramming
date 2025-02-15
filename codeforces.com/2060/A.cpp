#include <bits/stdc++.h>
#define int long long

void solve() {
  int a[6];
  std::cin >> a[1] >> a[2] >> a[4] >> a[5];
  int ans = 0;
  for (int i = -200; i <= 200; i++) {
    int cnt = 0;
    a[3] = i;
    for (int j = 1; j <= 3; j++) {
      if (a[j] + a[j + 1] == a[j + 2]) {
        cnt++;
      }
    }
    ans = std::max(ans, cnt);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}