#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("A.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      sum += x;
      cnt += (x > 0);
    }
    std::cout << (cnt == 1 ? sum : (sum + 1) / 2) << ' ' << sum << '\n';
  }
  return 0;
}