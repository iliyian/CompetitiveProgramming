// date: 2024-12-11 21:19:51
// tag: 四边循环的时候，务必注意往往不是正方形

#include <bits/stdc++.h>
#define int long long

int n, m;
std::vector<std::string> a(201);

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool in(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool check(int x, int y, int d) {
  std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
  while (in(x, y)) {
    vis[x][y] = 1;
    if (a[x][y] == '/') {
      d ^= 1;
      // if (d == 0) d = 1;
      // if (d == 1) d = 0;
      // if (d == 2) d = 3;
      // if (d == 2) d = 1;
    } else if (a[x][y] == '\\') {
      d = 3 - d;
      // if (d == 0) d = 1;
      // if (d == 1) d = 0;
      // if (d == 2) d = 3;
      // if (d == 3) d = 2;
    }
    x += dx[d], y += dy[d];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '.' && !vis[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  std::vector<std::string> ans;
  for (int i = 1; i <= n; i++) {
    if (check(1, i, 2)) {
      ans.push_back("N" + std::to_string(i));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (check(n, i, 0)) {
      ans.push_back("S" + std::to_string(i));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (check(i, 1, 1)) {
      ans.push_back("W" + std::to_string(i));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (check(i, m, 3)) {
      ans.push_back("E" + std::to_string(i));
    }
  }
  std::cout << ans.size() << '\n';
  for (auto &s : ans) {
    std::cout << s << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}