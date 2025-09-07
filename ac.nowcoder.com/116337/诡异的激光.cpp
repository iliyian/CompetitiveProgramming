#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> r(k), c(k);
  std::set<std::pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      s.insert({i, j});
    }
  }
  for (int i = 0; i < k; i++) {
    std::cin >> r[i] >> c[i];
    s.erase({r[i], c[i]});
  }
  auto [_x, _y] = *s.begin();
  std::vector<int> p(k);
  std::iota(p.begin(), p.end(), 0);
  auto mov = [&](int &x, int y) {
    if (x > y) x--;
    else x++;
  };
  auto move = [&](int sx, int sy, int tx, int ty) {
    while (sx != tx || sy != ty) {
      // std::cerr << sx << ' ' << sy << ' ' << tx << ' ' << ty << '\n';
      s.erase({sx, sy});
      if (sx == tx) {
        mov(sy, ty);
      } else if (sy == ty) {
        mov(sx, tx);
      } else {
        int r = rd() % 2;
        if (r) {
          mov(sy, ty);
        } else {
          mov(sx, tx);
        }
      }
    }
  };
  for (int t = 0; t < 10; t++) {
    std::shuffle(p.begin(), p.end(), rd);
    for (int i = 0; i < k; i += 2) {
      move(r[p[i]], c[p[i]], r[p[i + 1]], c[p[i + 1]]);
    }
  }
  if (s.empty()) {
    // std::cout << "fail\n";
    std::cout << _x << ' ' << _y << '\n';
  } else {
    std::cout << s.begin()->first << ' ' << s.begin()->second << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}