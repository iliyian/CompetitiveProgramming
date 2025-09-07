#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b;
  std::cin >> a >> b;
  int ans = LLONG_MAX / 3;
  for (int i = -10; i < 10; i++) {
    for (int j = -10; j < 10; j++) {
      int x = a + i, y = b + j;
      if ((y - x + 100) % 10 == (y + x + 100) % 10 && y >= x && 1 <= x && y <= (int)1e9) {
        // std::cerr << i << ' ' << j << ' ' << a << ' ' << b << '\n';
        ans = std::min(ans, std::abs(i) + std::abs(j));
      }
    }
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