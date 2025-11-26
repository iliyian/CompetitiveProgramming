#include <bits/stdc++.h>
#define int long long

int dx[2][3] = {
  {0, 1, 0} // 左下右
  ,
  {0, -1, 0} // 左上右
};
int dy[2][3] = {
  {-1, 1, 1}
  ,
  {-1, -1, 1}
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n * 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i * 2 - 1; j++) {
      std::cin >> a[i][j];
    }
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= x * 2 - 1;
  };
  std::vector<std::array<int, 5>> perm;
  for (int i = 0; i < 2; i++) {
    std::array<int, 5> p = {i, 1, 2, 3, 4};
    do {
      perm.push_back(p);
    } while (std::next_permutation(p.begin() + 1, p.end()));
  };
  auto get = [&](std::array<int, 5> a) {
    return std::ranges::lower_bound(perm, a) - perm.begin();
  };
  auto move = [&](int from, int d) {
    auto a = perm[from];
    int f = a[0];
    auto b = a;
    b[0] ^= 1;
    if (f) { // 倒三角
      if (d == 0) { // 左
        b[1] = a[3];
        b[2] = a[2];
        b[3] = a[4];
        b[4] = a[1];
      } else if (d == 2) { // 右
        b[1] = a[4];
        b[2] = a[1];
        b[3] = a[3];
        b[4] = a[2];
      } else { // 上
        b[1] = a[1];
        b[2] = a[4];
        b[3] = a[2];
        b[4] = a[3];
      }
    } else {
      if (d == 0) { // 左，应该同上右
        b[1] = a[2];
        b[2] = a[4];
        b[3] = a[3];
        b[4] = a[1];
      } else if (d == 2) { // right
        b[1] = a[4];
        b[2] = a[2];
        b[3] = a[1];
        b[4] = a[3];
      } else { // down
        b[1] = a[1];
        b[2] = a[3];
        b[3] = a[4];
        b[4] = a[2];
      }
    }
    return get(b);
  };
  std::vector<std::vector<std::vector<int>>> dis(48, std::vector<std::vector<int>>(n + 1, std::vector<int>(n * 2, -1)));
  int tx, ty;
  std::cin >> tx >> ty;
  std::queue<std::array<int, 3>> q;
  int from = 0;
  q.push({0, 1, 1});
  dis[0][1][1] = 0;
  if (a[1][1] != 4) {
    std::cout << -1 << '\n';
    return;
  }
  while (!q.empty()) {
    auto [u, x, y] = q.front(); q.pop();
    // std::cout << u << ' ' << x << ' ' << y << ' ' << dis[u][x][y] << '\n';
    // auto &from = perm[u];
    // for (int i = 0; i < 5; i++) {
    //   std::cout << from[i] << ' ';
    // }
    // std::cout << '\n';
    // std::cout << '\n';
    if (x == tx && y == ty) {
      std::cout << dis[u][x][y] << '\n';
      return;
    }
    int s = (y - 1) & 1;
    for (int i = 0; i < 3; i++) {
      int xx = x + dx[s][i], yy = y + dy[s][i];
      if (!in(xx, yy)) continue;
      int v = move(u, i);
      auto &now = perm[v];
      if (dis[v][xx][yy] == -1 && now[4] == a[xx][yy]) {
        dis[v][xx][yy] = dis[u][x][y] + 1;
        q.push({v, xx, yy});
      }
    }
  }
  std::cout << -1 << '\n';
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