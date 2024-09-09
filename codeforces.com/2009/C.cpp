#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int x, y, d;
  std::cin >> x >> y >> d;
  int ans = (x + d - 1) / d * 2;
  y -= ans / 2 * d;
  if (y > 0) {
    ans += (y + d - 1) / d * 2;
  } else if (y + d <= 0) {
    ans--;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}