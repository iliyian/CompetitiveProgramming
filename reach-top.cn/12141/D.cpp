#include <bits/stdc++.h>
#define int long long

bool check(int x) {
  while (x) {
    if (x % 10 == 7 || x % 10 == 8) {
      return true;
    }
    x /= 10;
  }
  return false;
}

void solve() {
  int n;
  while (std::cin >> n) {
    std::cout << (check(n) ? "Yes" : "No") << '\n';
  }
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