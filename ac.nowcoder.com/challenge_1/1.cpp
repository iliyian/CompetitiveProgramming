#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    ans += str.substr(0, str.find("16")) == "bnu";
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