#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m, h;
  std::cin >> n >> m >> h;
  std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2));
  std::array<std::vector<std::vector<int>>, 4> s;
  for (int i = 0; i < 4; i++) {
    s[i].assign(n + 2, std::vector<int>(m + 2));
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      {
        int d = 0;
        int xx = i + dx[d], yy = j + dy[d];
        if (a[i][j] < 0) {
          s[d][i][j] = s[d][xx][yy] + 1;
        } else if (a[i][j] < h) {
          s[d][i][j] = s[d][xx][yy];
        }
      }
      {
        int d = 3;
        int xx = i + dx[d], yy = j + dy[d];
        if (a[i][j] < 0) {
          s[d][i][j] = s[d][xx][yy] + 1;
        } else if (a[i][j] < h) {
          s[d][i][j] = s[d][xx][yy];
        }
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      {
        int d = 1;
        int xx = i + dx[d], yy = j + dy[d];
        if (a[i][j] < 0) {
          s[d][i][j] = s[d][xx][yy] + 1;
        } else if (a[i][j] < h) {
          s[d][i][j] = s[d][xx][yy];
        }
      }
      {
        int d = 2;
        int xx = i + dx[d], yy = j + dy[d];
        if (a[i][j] < 0) {
          s[d][i][j] = s[d][xx][yy] + 1;
        } else if (a[i][j] < h) {
          s[d][i][j] = s[d][xx][yy];
        }
      }
    }
  }
  std::vector<std::array<int, 3>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
          cnt += s[d][i][j];
        }
        if (cnt >= 3) {
          ans.push_back({cnt, -i, -j});
        }
      }
    }
  }
  std::sort(ans.begin(), ans.end(), std::greater<>());
  std::cout << ans.size() << '\n';
  std::cout << -ans[0][1] - 1 << ' ' << -ans[0][2] - 1 << '\n';
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