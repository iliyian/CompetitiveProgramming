#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-2, -2, -1, 1, 2, 2, 2, -1}, dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int ddx[] = {-1, 0, 1, 0}, ddy[] = {0, 1, 0, -1};

void solve(int n, int m, int k) {

// void solve() {
//   int n, m, k;
//   cin >> n >> m >> k;

  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  vector<vector<int>> vis(n + 1, vector<int>(m + 1));
  auto dfs = [&](auto self, int rest) -> bool {
    if (!rest) return true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!vis[i][j]) {
          bool f = true;
          for (int d = 0; d < 8; d += 2) {
            int xx = i + dx[d], yy = j + dy[d], xx2 = i + dx[d + 1], yy2 = j + dy[d + 1];
            int xxx = i + ddx[d / 2], yyy = j + ddy[d / 2];
            if (!in(xxx, yyy) || vis[xxx][yyy]) continue;
            if (in(xx, yy) && vis[xx][yy]) {
              f = false;
              break;
            }
            if (in(xx2, yy2) && vis[xx2][yy2]) {
              f = false;
              break;
            }
          }
          if (f) {
            vis[i][j] = true;
            if (self(self, rest - 1)) {
              return true;
            }
            vis[i][j] = false;
          }
        }
      }
    }
    return false;
  };
  bool f = dfs(dfs, k);
  if (f) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << vis[i][j];
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  // int _;
  // cin >> _;

  int a, b, c;
  cin >> a >> b >> c;

  solve(a, b, c);

  // for (int i = 30; i <= 36; i++) {
  //   solve(6, 6, i);
  // }

  // for (int i = 20; i <= 20; i++) {
  //   for (int j = 20; j <= 20; j++) {
  //     for (int k = 0; k <= i * j; k++) {
  //       solve(i, j, k);
  //     }
  //   }
  // }

  // while (_--) {
  //   solve();
  // }

  return 0;
}