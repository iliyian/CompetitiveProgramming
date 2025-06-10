// date: 2025-05-09 16:21:41
// tag: 涉及加加减减变相同的，要求最小操作数，往往是和gcd有关的，辗转相减嘛

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int g = 0;
  int f = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g = std::gcd(g, std::abs(a[i] - k));
    f |= a[i] < k;
    f |= (a[i] > k) << 1;
    f |= (a[i] == k) << 2;
  }
  if (f == 3 || (f & 4) && f != 4) {
    std::cout << -1 << '\n';
    return;
  }
  if (f == 4) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != k) {
      ans += std::abs(a[i] - k) / g - 1;
    }
  }
  std::cout << ans << '\n';
}    

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}