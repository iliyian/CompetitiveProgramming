#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 0; i <= 30 && i * 3 <= 50; i++) {
    for (int j = 0; i + j <= 30 && i * 3 + j * 2 <= 50; j++) {
      if (30 - i - j == 50 - i * 3 - j * 2) {
        std::cout << i << ' ' << j << ' ' << 30 - i - j << '\n';
      }
    }
  }
  return 0;
}