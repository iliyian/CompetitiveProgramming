#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  std::cin >> n >> a >> b;
  int ans = 0;
  for (int i = 2; i * a + b * 2 <= n; i += 2) {
    if ((n - i * a) % (b * 2) == 0) {
      std::cout << i << ' ' << (n - i * a) / b << '\n';
    }
  }
  return 0;
}