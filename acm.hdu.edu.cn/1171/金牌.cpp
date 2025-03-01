#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = 0, c0 = 0, c1 = 0;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    ans += str == "Au";
    if (str == "Ag") c0++;
    if (str == "Cu") c1++;
  }
  std::cout << ans + std::min(c0, c1) << '\n';
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