#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, l, r;
  std::cin >> n >> l >> r;
  int L = 1, R = n, ans = 0;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (mid * (mid - 1) / 2 + 1 <= l) L = mid + 1, ans = mid;
    else R = mid - 1;
  }
  // std::cerr << ans * (ans - 1) / 2 + ans << ' ' << ans << '\n';
  // std::cerr << (ans + 1) * ans / 2 + l - (ans * (ans - 1) / 2 + 1) + 1 << '\n';
  if (r >= (ans + 1) * ans / 2 + l - (ans * (ans - 1) / 2 + 1) + 1) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
  }
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