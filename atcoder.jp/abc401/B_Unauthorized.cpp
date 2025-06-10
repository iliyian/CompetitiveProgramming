#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  bool f = false;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    if (str == "login") {
      f = true;
    }
    if (str == "logout") {
      f = false;
    }
    if (str == "private" && !f) {
      ans++;
    }
  }
  std::cout << ans << '\n';
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