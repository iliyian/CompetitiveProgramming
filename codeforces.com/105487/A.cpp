#include <bits/stdc++.h>
#define int long long

void solve() {
  int z0, h, u0, v0, u1, v1;
  std::cin >> z0 >> h >> u0 >> v0 >> u1 >> v1;
  int n;
  std::cin >> n;
  while (n--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x >= std::min(u0, u1) && x <= std::max(u0, u1) && y >= std::min(v0, v1) && y <= std::max(v0, v1) && z >= z0 && z <= z0 + h) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
}