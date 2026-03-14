#include <bits/stdc++.h>
#define int long long

using i128 = __int128;

void solve() {
  int nn;
  std::cin >> nn;
  std::cout << nn << " is ";
  if (nn % 3 == 0) {
    int n = nn / 3;
    int l = 1, r = n, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      i128 val = i128(mid) * mid * mid;
      if (val <= n) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    if (ans != -1 && i128(ans) * ans * ans == n) {
      std::cout << "a triple flower" << '\n';
      return;
    }
  }
  if (nn % 2 == 0) {
    int n = nn / 2;
    int l = 1, r = n, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      i128 val = i128(mid) * mid;
      if (val <= n) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    if (ans != -1 && i128(ans) * ans == n) {
      std::cout << "a double flower" << '\n';
      return;
    }
  }
  std::cout << nn << '\n';
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