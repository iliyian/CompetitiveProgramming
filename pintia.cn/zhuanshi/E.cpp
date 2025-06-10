#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, r, c;
  std::cin >> n >> r >> c;
  std::vector<std::pair<int, int>> pos(n + 1);
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      int x;
      std::cin >> x;
      pos[x] = {i, j};
    }
  }
  int q;
  std::cin >> q;
  int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    bool f = false;
    for (int i = 0; i < 4; i++) {
      int xx = pos[x].first + dx[i], yy = pos[x].second + dy[i];
      if (xx == pos[y].first && yy == pos[y].second) {
        std::cout << "yes\n";
        f = true;
        break;
      }
    }
    if (!f) {
      std::cout << "no\n";
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}