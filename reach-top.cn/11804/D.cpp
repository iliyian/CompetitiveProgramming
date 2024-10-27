#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  std::cin >> n >> a >> b;
  int ans = 0;
  for (int i = 1; i * a + b <= n; i++) {
    if ((n - i * a) % b == 0) {
      ans++;
    }
  }
  std::cout << ans << '\n';
  return 0;
}