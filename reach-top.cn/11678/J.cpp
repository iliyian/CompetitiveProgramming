#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int t = n, len = 0;
  while (t) len++, t /= 10;
  t = n;
  int cur = 0;
  bool f = true;
  while (t) {
    cur += pow(t % 10, len);
    if (cur > n) {
      f = false;
      break;
    }
    t /= 10;
  }
  std::cout << (f && cur == n ? "T" : "F") << '\n';
}

signed main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}