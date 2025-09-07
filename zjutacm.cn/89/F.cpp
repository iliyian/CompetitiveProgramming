#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mp[a[i]]++;
  }
  int ans = 0;
  for (auto k : mp) {
    ans = std::max(ans, k.second);
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