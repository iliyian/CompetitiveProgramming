#include <bits/stdc++.h>
#define int long long

void solve() {
  int x;
  std::cin >> x;
  std::vector<int> ans;
  while (x) ans.push_back(x % 2), x /= 2;
  std::reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    std::cout << i;
  }
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}