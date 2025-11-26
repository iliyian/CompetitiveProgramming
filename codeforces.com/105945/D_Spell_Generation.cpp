#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    ans += (str[i] - '0') << (str.size() - i - 1);
  }
  std::cout << ans << '\n';
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