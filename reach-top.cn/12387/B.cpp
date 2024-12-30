#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int a[3];
  std::cin >> a[0] >> a[1] >> a[2];
  std::sort(a, a + 3);
  std::cout << a[1] << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}