#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int x, y;
  std::cin >> x >> y;
  x = std::abs(x), y = std::abs(y);
  if (x == y) {
    std::cout << x * 2 << '\n';
    return;
  }
  int ans = std::min(x, y) * 2 + (std::max(x, y) - std::min(x, y) - 1) * 2 + 1;
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}