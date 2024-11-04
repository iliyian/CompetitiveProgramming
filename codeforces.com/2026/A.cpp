#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int x, y, k;
  std::cin >> x >> y >> k;
  int m = std::min(x, y);
  std::cout << 0 << ' ' << 0 << ' ' << m << ' ' << m << '\n';
  std::cout << m << ' ' << 0 << ' ' << 0 << ' ' << m << '\n';
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