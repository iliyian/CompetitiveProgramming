// date: 2025-02-26 16:28:14
// tag: 根号分块

#include <bits/stdc++.h>
#define int long long

int solve(int n) {
  int ans = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    ans += (n / l) * (r - l + 1) * (l + r) / 2;
  }
  return ans;
}

void solve() {
  int x, y;
  std::cin >> x >> y;
  std::cout << solve(y) - solve(x - 1) << '\n';
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