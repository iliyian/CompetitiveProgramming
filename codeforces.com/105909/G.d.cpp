#include <bits/stdc++.h>
#define int long long

void solve() {
  int sx, sy, tx, ty, x, y;
  std::cin >> sx >> sy >> tx >> ty >> x >> y;
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (ch == 'W') x = x * 2;
    else if (ch == 'S') x = x / 2;
    else if (ch == 'A') x--;
    else x++;
    // if (std::abs(x) >= (int)1e9) {
      std::cout << x << ' ' << i << '\n';
    // }
  }
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