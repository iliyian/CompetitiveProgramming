// date: 2024-06-30 22:06:24
// tag: 二位差分与二维前缀和

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 3, std::vector<int>(m + 3));
  std::vector<int> pa(n * m + 1), siz(n * m + 1);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
  };
  auto id = [&](int x, int y) {
    return (x - 1) * m + y;
  };
  iota(pa.begin() + 1, pa.end(), 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++ ){
      char ch;
      std::cin >> ch;
      a[i][j] = ch == '#';
      if (a[i][j]) {
        siz[id(i, j)] = 1;
      }
    }
  }
  std::vector<int> zr(n + 1), zc(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        for (int d = 0; d < 4; d++) {
          int xx = i + dx[d], yy = j + dy[d];
          if (a[xx][yy]) {
            merge(id(i, j), id(xx, yy));
          }
        }
      } else {
        zr[i]++;
        zc[j]++;
      }
    }
  }
  std::vector<int> l(n * m + 1, m), r(n * m + 1), u(n * m + 1, n), d(n * m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        int x = find(find, id(i, j));
        l[x] = std::min(l[x], j);
        r[x] = std::max(r[x], j);
        u[x] = std::min(u[x], i);
        d[x] = std::max(d[x], i);
      }
    }
  }
  std::vector<std::vector<int>> f(n + 3, std::vector<int>(m + 3));
  for (int x = 1; x <= n * m; x++) {
    if (x == pa[x]) {
      l[x]--, r[x]++;
      u[x]--, d[x]++;
      f[u[x]][l[x]] -= siz[x];
      f[0][l[x]] += siz[x];
      f[u[x]][0] += siz[x];

      f[d[x] + 1][0] -= siz[x];
      f[0][r[x] + 1] -= siz[x];
      f[d[x] + 1][l[x]] += siz[x];
      f[u[x]][r[x] + 1] += siz[x];

      f[d[x] + 1][r[x] + 1] -= siz[x];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] += f[i][j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j] += f[i - 1][j];
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cur = zr[i] + zc[j] - !a[i][j] + f[i][j];
      ans = std::max(ans, cur);
    }
  }

  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("H2.in", "r", stdin);
  freopen("H2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}