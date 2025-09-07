#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, x, y;
  std::cin >> a >> x >> y;
  if (x > y) std::swap(x, y);
  std::cout << (x <= a && a <= y ? "NO" : "YES") << '\n';
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