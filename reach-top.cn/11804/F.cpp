#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int ans = 0;
  for (int i = 1; i + 2 + 5 <= 100; i++) {
    for (int j = 1; i + j * 2 + 5 <= 100; j++) {
      if ((100 - i - j * 2) % 5 == 0) {
        ans++;
        // std::cout << i << ' ' << j << ' ' << (100 - i - j * 2) / 5 << '\n';
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}