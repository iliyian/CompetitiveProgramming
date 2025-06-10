// date: 2025-05-19 14:28:55
// tag: 绷不住了，把define long long删了就行

#include <bits/stdc++.h>
// #define int long long

void solve() {
  int c[3] {}, w[3] {};
  for (int i = 0; i < 3; i++) {
    std::cin >> c[i];
  }
  int ini[3] {};
  for (int i = 0; i < 3; i++) {
    std::cin >> w[i];
    ini[i] = w[i];
  }
  int t;
  std::cin >> t;
  std::vector<std::vector<std::vector<int>>> dis(301, std::vector<std::vector<int>>(301, std::vector<int>(301, INT_MAX / 2)));
  std::vector<std::vector<std::vector<std::array<int, 3>>>> prv(301, std::vector<std::vector<std::array<int, 3>>>(301, std::vector<std::array<int, 3>>(301)));
  dis[w[0]][w[1]][w[2]] = 0;
  // std::priority_queue<std::array<int, 4>> q;
  std::queue<std::array<int, 4>> q;
  q.push({0, w[0], w[1], w[2]});
  while (!q.empty()) {
    auto [d, x, y, z] = q.front(); q.pop();
    if (dis[x][y][z] != d) continue;
    if (x == t || y == t || z == t) {
      std::stack<std::array<int, 3>> s;
      while (ini[0] != x || ini[1] != y || ini[2] != z) {
        s.push({x, y, z});
        int xx[3] = {x, y, z};
        x = prv[xx[0]][xx[1]][xx[2]][0];
        y = prv[xx[0]][xx[1]][xx[2]][1];
        z = prv[xx[0]][xx[1]][xx[2]][2];
      }
      std::cout << s.size() << '\n';
      while (!s.empty()) {
        auto [x, y, z] = s.top(); s.pop();
        std::cout << x << ' ' << y << ' ' << z << '\n';
      }
      return;
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j) {
          int xx[3] = {x, y, z};
          int tmp = std::min(xx[i], c[j] - xx[j]);
          if (!tmp) continue;
          xx[i] -= tmp, xx[j] += tmp;
          if (dis[xx[0]][xx[1]][xx[2]] > dis[x][y][z] + 1) {
            dis[xx[0]][xx[1]][xx[2]] = dis[x][y][z] + 1;
            prv[xx[0]][xx[1]][xx[2]] = {x, y, z};
            q.push({dis[xx[0]][xx[1]][xx[2]], xx[0], xx[1], xx[2]});
          }
        }
      }
    }
    int mn = 301;
    if (x > 0) mn = std::min(mn, x);
    if (y > 0) mn = std::min(mn, y);
    if (z > 0) mn = std::min(mn, z);
    for (int i = 0; i < 3; i++) {
      int xx[3] = {x, y, z};
      if (xx[i] != mn) continue;
      xx[i] = 0;
      if (dis[xx[0]][xx[1]][xx[2]] > dis[x][y][z] + 1) {
        dis[xx[0]][xx[1]][xx[2]] = dis[x][y][z] + 1;
        prv[xx[0]][xx[1]][xx[2]] = {x, y, z};
        q.push({dis[xx[0]][xx[1]][xx[2]], xx[0], xx[1], xx[2]});
      }
    }
  };
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