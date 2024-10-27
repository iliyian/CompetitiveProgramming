#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  n *= 10;
  int ans = 0;
  for (int i = 1; i * 8 + 2 + 1 <= n; i++) {
    for (int j = 1; i * 8 + j * 2 + 1 <= n; j++) {
      int k = n - i * 8 - j * 2;
      if (i + j + k > 30) {
        ans++;
        // std::cout << i << ' ' << j << ' ' << k << '\n';
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}