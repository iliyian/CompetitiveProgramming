#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int ans6 = 0, ans1 = 0;
  for (int i = 1; i <= n; i++) {
    int t = i;
    while (t) ans6 += t % 10 == 6, ans1 += t % 10 == 1, t /= 10;
  }
  std::cout << ans6 << ' ' << ans1 << '\n';
  return 0;
}