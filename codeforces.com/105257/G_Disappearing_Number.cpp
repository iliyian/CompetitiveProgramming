#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  std::string str;
  int x;
  std::cin >> str >> x;
  std::vector<int> dp(20);
  int base = 1;
  for (int i = 1; i <= 19; i++) {
    dp[i] = dp[i - 1] * 9 + base;
    base *= 10;
    // std::cerr << dp[i] << ' ';
  }
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] - '0' == x) {
      ans += std::stoll(str.substr(i, str.size() - i));
      assert(false);
      break;
    } else if (str[i] - '0' > x) {
      ans += dp[str.size() - i - 1] * (str[i] - '0' - 1) + powl(10ll, str.size() - i - 1);
    } else {
      ans += dp[str.size() - i - 1] * (str[i] - '0');
    }
    // std::cerr << ans << '\n';
  }
  // std::cout << ans << '\n';
  std::cout << std::stoll(str) - ans + 1 << '\n';
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