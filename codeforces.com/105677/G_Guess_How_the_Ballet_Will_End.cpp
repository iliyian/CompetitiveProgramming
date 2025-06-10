#include <bits/stdc++.h>
#define int long long

void solve() {
  int R, n;
  std::cin >> R >> n;
  int l = 0, r = R;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    l += x, r += x;
    l = std::min(R, std::max(l, 0ll));
    r = std::max(0ll, std::min(r, R));
    // std::cerr << l << ' ' << r << '\n';
  }
  if (l == r) {
    std::cout << l << '\n';
  } else {
    std::cout << "uncertain\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}