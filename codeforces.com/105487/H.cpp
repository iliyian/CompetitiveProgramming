#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  long double ans = 0;
  int len = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1') {
      len++;
    } else {
      ans += (len <= 2 ? sqrtl(len) : (len % 2 ? (len + 1) / 2 : (len - 2) / 2 + sqrtl(2)));
      len = 0;
    }
  }
      ans += (len <= 2 ? sqrtl(len) : (len % 2 ? (len + 1) / 2 : (len - 2) / 2 + sqrtl(2)));
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
}