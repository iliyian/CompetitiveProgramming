#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("F.in", "r", stdin);
  int n;
  std::cin >> n;
  int cur = 1500, ans = -1;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (cur + x >= 4000 && ans == -1) {
      ans = i;
    }
    cur += x;
  }
  std::cout << ans << '\n';
  return 0;
}