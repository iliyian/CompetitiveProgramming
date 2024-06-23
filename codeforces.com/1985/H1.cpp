// date: 2024-06-16 11:05:02
// tag: 枚举，dsu，图论

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n + 2, vector<char>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> pa(n * m + 1), siz(n * m + 1, 1);
  iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
  };
  auto id = [&](int i, int j) -> int {
    return (i - 1) * m + j;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '#') {
        for (int d = 0; d < 4; d++) {
          int xx = i + dx[d], yy = j + dy[d];
          if (a[xx][yy] == '#') {
            merge(id(i, j), id(xx, yy));
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    unordered_map<int, int> cnt;
    int cur = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i - 1][j] == '#') {
        int x = find(find, id(i - 1, j));
        cnt[x] = siz[x];
      }
      if (a[i + 1][j] == '#') {
        int x = find(find, id(i + 1, j));
        cnt[x] = siz[x];
      }
      if (a[i][j] == '#') {
        int x = find(find, id(i, j));
        cnt[x] = siz[x];
      }
      if (a[i][j] == '.') {
        cur++;
      }
    }
    for (auto &[k, v] : cnt) {
      cur += v;
    }
    ans = max(ans, cur);
  }

  for (int j = 1; j <= m; j++) {
    unordered_map<int, int> cnt;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i][j + 1] == '#') {
        int x = find(find, id(i, j + 1));
        cnt[x] = siz[x];
      }
      if (a[i][j - 1] == '#') {
        int x = find(find, id(i, j - 1));
        cnt[x] = siz[x];
      }
      if (a[i][j] == '#') {
        int x = find(find, id(i, j));
        cnt[x] = siz[x];
      }
      if (a[i][j] == '.') {
        cur++;
      }
    }
    for (auto &[k, v] : cnt) {
      cur += v;
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  // cout << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("H1.in", "r", stdin);
  freopen("H1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}