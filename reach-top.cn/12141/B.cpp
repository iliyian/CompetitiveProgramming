#include <bits/stdc++.h>
#define int long long

void solve() {
  int ans = INT_MIN;
  std::string str;
  std::cin >> str;
  int prv = -1;
  while (prv != str.size()) {
    int now = str.find(',', prv + 1);
    if (now == str.npos) now = str.size();
    ans = std::max(ans, std::stoll(str.substr(prv + 1, now - prv)));
    prv = now;
  }
  std::cout << ans << '\n';
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