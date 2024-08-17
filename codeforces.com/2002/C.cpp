#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  auto dis = [&](int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  };
  int sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;
  int d = dis(sx, sy, tx, ty);
  for (int i = 1; i <= n; i++) {
    auto [x, y] = a[i];
    if (dis(x, y, tx, ty) <= d) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
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