// date: 2024-07-15 14:14:45
// tag: 不完全枚举

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

void solve() {
  int x, y;
  std::cin >> x >> y;
  if (x > y) std::swap(x, y);
  int ans = inf;

  for (int k = 1; k <= 3e5; k++) {
    ans = std::min(ans, (x + k - 1) / k + (y + k - 1) / k + k - 1);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}