#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("L.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h1, d1, t1, h2, d2, t2;
  std::cin >> h1 >> d1 >> t1 >> h2 >> d2 >> t2;
  int need1 = ((h2 + d1 - 1) / d1 - 1) * t1; // 到达此时间2必死
  int need2 = ((h1 + d2 - 1) / d2 - 1) * t2; // 到达此时间1必死
  // std::cout << need1 << ' ' << need2 << '\n';
  if (need1 < need2) {
    std::cout << "player one\n";
  } else if (need1 > need2) {
    std::cout << "player two\n";
  } else {
    std::cout << "draw\n";
  }
  return 0;
}