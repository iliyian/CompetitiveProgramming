#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int xc, yc, k;
  std::cin >> xc >> yc >> k;
  if (k & 1) {
    std::cout << xc << ' ' << yc << '\n';
    k--;
  }
  for (int i = 1; i <= k; i++) {
    std::cout << xc + (i & 1 ? 1 : -1) * (i + 1) / 2 << ' ' << yc + (i & 1 ? 1 : -1) * (i + 1) / 2 << '\n';
  }
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