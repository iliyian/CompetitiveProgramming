#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> cnt(11);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = n * (n + 1) / 2;
  for (int v = 1; v <= 10; v++) {
    int cnt = 0;
    std::vector<std::vector<int>> mp(n * 3 + 1);
    mp[0 + n].push_back(0);
    std::vector<int> p(11, -1);
    for (int i = 1; i <= n; i++) {
      p[a[i]] = i;
      cnt += a[i] <= v;
      auto &mpp = mp[2 * cnt - i + n];

      if (p[v] != -1) {
        auto q = std::lower_bound(mpp.begin(), mpp.end(), p[v]) - mpp.begin();
        // std::cout << v << ' ' << i << ' ' << p[v] << ' ' << 2 * cnt - i + n << '\n';
        ans -= q;
      }

      mp[2 * cnt - i + n].push_back(i);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}