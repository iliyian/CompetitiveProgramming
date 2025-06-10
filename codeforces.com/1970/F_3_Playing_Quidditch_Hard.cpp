// date: 2025-03-29 21:44:28
// tag: 小模拟，jiangly也写的很优雅。不过估计自己一次写对还得是感谢样例比较强。总之还是一次写对了。

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> b(128, {0, 0, 0}), r(128, {0, 0, 0});
  std::vector<std::pair<int, int>> pos(128);
  std::vector<std::pair<int, int>> rg, bg;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::string str;
      std::cin >> str;
      if (str == ".Q" || str == ".B" || str == ".S") {
        pos[str.back()] = {i, j};
      }
      if (str.front() == 'R') {
        if (isdigit(str.back())) {
          r[str.back()] = {i, j, 0};
        } else {
          rg.push_back({i, j});
        }
      }
      if (str.front() == 'B') {
        if (isdigit(str.back())) {
          b[str.back()] = {i, j, 0};
        } else {
          bg.push_back({i, j});
        }
      }
    }
  }
  int t;
  std::cin >> t;
  int rans = 0, bans = 0;
  std::string urdl = "URDL";
  for (int i = 0; i < t; i++) {
    std::string et;
    std::cin >> et;
    std::string s1, s2;
    std::cin >> s1;
    if (urdl.find(s1) != std::string::npos) {
      int d = urdl.find(s1);
      if (et.front() == '.') {
        auto &[x, y] = pos[et.back()];
        x += dx[d], y += dy[d];
        if (et.back() == 'B') {
          for (char c = '0'; c <= '9'; c++) {
            if (b[c][0] == x && b[c][1] == y) {
              std::cout << i << ' ' << "B" << c << ' ' << "ELIMINATED\n";
              b[c][0] = b[c][1] = 0;
            }
          }
          for (char c = '0'; c <= '9'; c++) {
            if (r[c][0] == x && r[c][1] == y) {
              std::cout << i << ' ' << "R" << c << ' ' << "ELIMINATED\n";
              r[c][0] = r[c][1] = 0;
            }
          }
        }
      } else {
        auto &[x, y, z] = (et.front() == 'R' ? r : b)[et.back()];
        x += dx[d], y += dy[d];
        if (z) {
          pos[z].first += dx[d];
          pos[z].second += dx[d];
        }
        if (x == pos['B'].first && y == pos['B'].second) {
          std::cout << i << ' ' << et << ' ' << "ELIMINATED\n";
          x = 0, y = 0, z = 0;
        }
      }
    } else {
      auto &[x, y, z] = (et.front() == 'R' ? r : b)[et.back()];
      if (s1 == "T") {
        auto &[xq, yq] = pos['Q'];
        for (auto [xx, yy] : rg) {
          if (xx == x && yy == y) {
            z = 0;
            xq = (n + 1) / 2, yq = (m + 1) / 2;
            std::cout << i << ' ' << "BLUE" << ' ' << "GOAL" << '\n';
            bans++;
            break;
          }
        }
        for (auto [xx, yy] : bg) {
          if (xx == x && yy == y) {
            z = 0;
            xq = (n + 1) / 2, yq = (m + 1) / 2;
            std::cout << i << ' ' << "RED" << ' ' << "GOAL" << '\n';
            rans++;
            break;
          }
        }
      } else if (s1 == "C") {
        std::cin >> s2;
        if (s2.back() == 'Q') {
          z = 'Q';
        } else if (s2.back() == 'S') {
          std::cout << i << ' ' << (et.front() == 'R' ? "RED" : "BLUE") << ' ' << "CATCH GOLDEN SNITCH" << '\n';
          (et.front() == 'R' ? rans : bans) += 10;
          break;
        }
      } else {
        assert(false);
      }
    }
  }
  std::cout << "FINAL SCORE: " << rans << ' ' << bans << '\n';
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