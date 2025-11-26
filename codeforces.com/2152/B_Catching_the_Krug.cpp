#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, rk, ck, rd, cd;
  std::cin >> n >> rk >> ck >> rd >> cd;
  int x = (rk > rd ? n : rk < rd ? 0 : rd);
  int y = (ck > cd ? n : ck < cd ? 0 : cd);
  std::cout << std::max(std::abs(x - rd), std::abs(y - cd)) << '\n';
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