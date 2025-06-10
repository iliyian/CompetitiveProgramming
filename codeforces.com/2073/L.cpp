#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int r, c, n, p;
  std::cin >> r >> c >> n >> p;
  std::vector<std::vector<int>> a(r + 1, std::vector<int>(c + 1));
  std::vector<std::array<int, 3>> v;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      std::cin >> a[i][j];
      if (a[i][j]) {
        v.push_back({a[i][j], i, j});
      }
    }
  }
  std::sort(v.begin(), v.end());
  std::set<int> ans;
  for (int i = p - 1; i >= 0; i--) {
    auto [val, x, y] = v[i];
    for (int d = 0; d < 4; d++) {
      int xx = x + dx[d], yy = y + dy[d];
      if (xx >= 1 && xx <= r && yy >= 1 && yy <= c && a[xx][yy] && a[xx][yy] + (p - 1 - i) <= n) {
        ans.insert(a[xx][yy] + (p - 1 - i));
      }
    }
  }
  std::cout << ans.size() << "/" << n - 1 << '\n';
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