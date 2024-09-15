#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  int x, y;
  std::cin >> x >> y;
  int a;
  std::cin >> a;
  if (x > y) std::swap(x, y);
  if (a < x) {
    std::cout << x - 1 << '\n';
  } else if (a > y) {
    std::cout << n - y << '\n';
  } else {
    std::cout << (y - x) / 2 << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B1.in", "r", stdin);
  freopen("B1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}