#include <bits/stdc++.h>
#define int long long

signed main() {
  int n, p;
  std::cin >> n >> p;
  if (p > n * 9) {
    std::cout << 1;
    for (int i = 1; i < n; i++) {
      std::cout << 0;
    }
    return 0;
  }
  std::string ans(n, '9');
  int d = 9 * n - p;
  if (d <= 8) {
    ans[0] -= d;
    std::cout << ans << '\n';
    return 0;
  }
  d -= 8;
  ans[0] = '1';
  int len = d / 9;
  for (int i = 1; i <= len; i++) {
    ans[i] = '0';
  }
  d -= len * 9;
  ans[len + 1] -= d;
  std::cout << ans << '\n';
  return 0;
}