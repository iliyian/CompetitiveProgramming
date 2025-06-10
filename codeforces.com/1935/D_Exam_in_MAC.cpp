// date: 2025-05-08 19:25:29
// tag: 水题，不知道说啥，疑似最简单的容斥

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = (c + 1) * (c + 2) / 2;
  for (int i = 1; i <= n; i++) {
    ans -= (a[i] + 2) / 2;
  }
  for (int i = 1; i <= n; i++) {
    ans -= c - a[i] + 1;
  }
  std::array<std::vector<int>, 2> b;
  for (int i = 1; i <= n; i++) {
    b[a[i] % 2].push_back(a[i]);
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < b[t].size(); i++) {
      auto p = std::upper_bound(b[t].begin() + i, b[t].end(), 2 * c - b[t][i]) - b[t].begin() - i;
      // std::cerr << p << " \n"[i == n];
      ans += p;
    }
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