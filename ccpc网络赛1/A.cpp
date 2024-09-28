#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;

bool in(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("A.in", "r", stdin);
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    for (int j = 0; j < m; j++) {
      a[i][j + 1] = (str[j] == '#' ? -2 : 0);
    }
  }
  // 找接边界的.
  auto dfs = [&](auto self, int x, int y) -> void {
    if (!in(x, y) || a[x][y]) return;
    a[x][y] = -1;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      self(self, xx, yy);
    }
  };
  for (int i = 1; i <= n; i++) {
    dfs(dfs, i, 1);
    dfs(dfs, i, m);
  }
  for (int i = 1; i <= m; i++) {
    dfs(dfs, 1, i);
    dfs(dfs, n, i);
  }
  // 给其他.集合标号
  int cnt = 0;
  auto dfs2 = [&](auto self, int x, int y, int cnt) -> void {
    if (!in(x, y) || a[x][y]) return;
    a[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      self(self, xx, yy, cnt);
    }
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        dfs2(dfs2, i, j, ++cnt);
      }
    }
  }

  std::set<int> s;
  auto dfs3 = [&](auto self, int x, int y) {
    if (!in(x, y)) return;
    if (a[x][y] > 0) {
      s.insert(a[x][y]);
      return;
    }
    if (a[x][y] != -2) return;
    a[x][y] = -3;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      self(self, xx, yy);
    }
  };
  std::array<int, 3> ans = {0, 0, 0};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == -2) {
        s.clear();
        dfs3(dfs3, i, j);
        if (s.size() <= 2) {
          ans[s.size()]++;
        }
      }
    }
  }
  std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  return 0;
}