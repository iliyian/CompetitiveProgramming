#include <bits/stdc++.h>
#define int long long

void solve() {
  int sx, sy, tx, ty, x, y;
  std::cin >> sx >> sy >> tx >> ty >> x >> y;
  for (int i = 0; i < 30; i++) {
    std::cout << "S";
    sy--;
  }
  std::string ans;
  while (y) {
    if (y & 1) ans.push_back('D'), tx--;
    ans.push_back('W'), ty--;
    y >>= 1;
  }
  std::reverse(ans.begin(), ans.end());
  std::cerr << tx << ' ' << ty << '\n';
  if (sx < tx) {
    for (int i = 0; i < tx - sx; i++) {
      std::cout << "D";
      // sx++;
    }
  } else if (sx > tx) {
    for (int i = 0; i < sx - tx; i++) {
      std::cout << "A";
      // sx--;
    }
  }
  for (int i = 0; i < 30; i++) {
    std::cout << "S";
    sy--;
  }
  if (sy < ty) {
    for (int i = 0; i < ty - sy; i++) {
      std::cout << "W";
      // sy++;
    }
  } else if (sy > ty) {
    for (int i = 0; i < sy - ty; i++) {
      std::cout << "S";
      // sy--;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}