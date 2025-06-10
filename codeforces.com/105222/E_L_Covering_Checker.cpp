#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
std::string DLUR = "DLUR";

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  int cc = 0, cl = 0, cu = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
    for (int j = 1; j <= m; j++) {
      cnt += a[i][j] == '.';
    }
  }
  if (cnt != 1 || a[1][m] != '.') {
    std::cout << "No\n";
    return;
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'C') {
        for (int d = 0; d < 4; d++) {
          int x1 = i + dx[d], y1 = j + dy[d], x2 = i + dx[(d + 1) % 4], y2 = j + dy[(d + 1) % 4];
          if (!in(x1, y1) || !in(x2, y2)) continue;
          if (a[x1][y1] != DLUR[d] || a[x2][y2] != DLUR[(d + 1) % 4]) continue;
          a[x1][y1] = a[i][j] = a[x2][y2] = '.';
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '.') {
        std::cout << "No\n";
        // std::cerr << i << ' ' << j << '\n';
        return;
      }
    }
  }
  std::cout << "Yes\n";
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