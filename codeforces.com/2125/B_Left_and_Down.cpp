#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, k;
  std::cin >> a >> b >> k;
  int g = std::gcd(a, b);
  a /= g, b /= g;
  if (a <= k && b <= k) {
    std::cout << 1 << '\n';
    return;
  }
  std::cout << 2 << '\n';
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