#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> ans(10);
  for (auto &i : a) {
    std::cin >> i;
    while (i) {
      ans[i % 10]++;
      i /= 10;
    }
  }
  for (int i = 0; i < 10; i++) {
    std::cout << i << ' ' << ans[i] << '\n';
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