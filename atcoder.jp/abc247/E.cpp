#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E.in", "r", stdin);

  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int lstx = 0, lsty = 0, la = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == x) lstx = i;
    if (a[i] == y) lsty = i;
    if (a[i] > x || a[i] < y) la = i, lstx = 0, lsty = 0;
    if (lstx && lsty) {
      ans += std::min(lstx, lsty) - la;
    }
  }
  std::cout << ans << '\n';
  
  return 0;
}