#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int a1, a2, b1, b2;
  std::cin >> a1 >> a2 >> b1 >> b2;
  int ans = (a1 >= b1 && a2 > b2 || a1 > b1 && a2 >= b2) + (a1 >= b2 && a2 > b1 || a1 > b2 && a2 >= b1);
  ans *= 2;
  std::cout << ans << '\n';
}

int32_t main() {
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