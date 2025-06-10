#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> x(n + 1), y(n + 1);
  std::multiset<int> sx, sy;
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i];
    sx.insert(x[i]), sy.insert(y[i]);
  }
  if (n == 1) {
    std::cout << 1 << '\n';
    return;
  }
  int ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    sx.erase(sx.find(x[i]));
    sy.erase(sy.find(y[i]));
    int dx = *sx.rbegin() - *sx.begin() + 1;
    int dy = *sy.rbegin() - *sy.begin() + 1;
    auto cur = dx * dy;
    if (cur == n - 1) {
      cur = std::min((dx + 1) * dy, (dy + 1) * dx);
    }
    ans = std::min(ans, cur);
    sx.insert(x[i]);
    sy.insert(y[i]);
  }
  std::cout << std::max(ans, n) << '\n';
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