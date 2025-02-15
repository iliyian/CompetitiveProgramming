#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> mp;
  int mn = INT_MAX;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    mp[x]++;
    mn = std::min(mn, x);
    mx = std::max(mx, x);
  }
  for (int i = mn; i <= mx + 1; i++) {
    if (mp[i] == 0) continue;
    if (mp[i] == 1) {
      std::cout << "No\n";
      return;
    }
    mp[i + 1] += mp[i] - 2;
    mp[i] = 2;
  }
  // for (auto [k, v] : mp) {
  //   std::cerr << k << ' ' << v << '\n';
  // }
  // std::cerr << '\n';
  std::cout << "Yes\n";
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