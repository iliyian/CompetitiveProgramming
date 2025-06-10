#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a;
  for (int i = 1; i <= n; i++) {
    int x, r;
    std::cin >> x >> r;
    a.push_back({x - r, x + r});
  }
  std::sort(a.begin(), a.end());
  int pr = a[0].second, ans = 0;
  for (int i = 1; i < a.size(); i++) {
    auto [l, r] = a[i];
    if (l > pr) {
      ans += l - pr;
    }
    pr = std::max(pr, r);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}