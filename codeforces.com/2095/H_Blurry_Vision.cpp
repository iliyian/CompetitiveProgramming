#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string ans[] = {
    "CODEFORCES",
    "EYE",
    "TESTING",
    "SYSTEM",
    "APRIL",
    "FOOLS",
    "YOU",
    "READ",
    "POORLY",
    "THE",
    "EYEGLASSES"
  };
  int n;
  std::cin >> n;
  std::cout << ans[n - 1] << '\n';
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