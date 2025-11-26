#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  bool f = false;
  if (n > m) {
    std::swap(n, m);
    f = true;
  }
  std::vector<int> a = {n};
  int nn = n / 2, d = n - 1, mm = m / 2;
  for (int i = 1; i <= nn; i++) {
    a.push_back(a.back() + d);
    d -= 2;
  }
  std::vector<int> b = {n};
  if (n == m) {
    b.clear();
    for (int i = 0; i <= mm; i++) {
      b.push_back(n - 1 - i * 2);
    }
  } else {
    int t = m - n - 1, d = 1;
    for (int i = 1; i < mm; i++) {
      if (i > t) {
        d = 2;
      }
      b.push_back(std::max(0ll, b.back() - d));
    }
  }
  // for (int i : a) {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';
  // for (int i : b) {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';
  std::vector<std::vector<int>> ans(nn + 1, std::vector<int>(mm + 1));
  for (int i = 0; i <= nn; i++) {
    ans[i][0] = a[i];
  }
  for (int j = 1; j <= mm; j++) {
    for (int i = 0; i <= nn; i++) {
      ans[i][j] = ans[i][j - 1] + b[j - 1];
    }
  }
  // for (int i = 0; i <= nn; i++) {
  //   for (int j = 0; j <= mm; j++) {
  //     std::cout << ans[i][j] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  if (f) {
    for (int j = 0; j <= m; j++) {
      for (int i = 0; i <= n; i++) {
        int x = std::min(i, n - i), y = std::min(j, m - j);
        std::cout << ans[x][y] << ' ';
      }
      std::cout << '\n';
    }
  } else {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        int x = std::min(i, n - i), y = std::min(j, m - j);
        std::cout << ans[x][y] << ' ';
      }
      std::cout << '\n';
    }
  }
}

void solve_full() {
  int n, m;
  std::cin >> n >> m;
  auto in = [&](int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= m;
  };
  std::vector<int> a, b;
  for (int i = 0; i <= n / 2; i++) {
    for (int j = 0; j <= 0; j++) {
      std::set<std::vector<std::pair<int, int>>> s;
      for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
          if (x != i || y != j) {
            int x3 = i + y - j;
            int y3 = j + i - x;
            int x4 = x + y - j;
            int y4 = y + i - x;
            std::vector<std::pair<int, int>> v = {{i, j}, {x, y}, {x3, y3}, {x4, y4}};
            std::ranges::sort(v);
            if (in(x3, y3) && in(x4, y4)) {
              s.insert(v);
            }
          }
        }
      }
      std::cout << s.size() << ' ';
    }
    std::cout << '\n';
  }
}

auto solve(int n, int m) {
  // int n, m;
  // std::cin >> n >> m;
  auto in = [&](int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= m;
  };
  std::vector<int> a, b;
  for (int i = 0; i <= n / 2; i++) {
    for (int j = 0; j <= 0; j++) {
      std::set<std::vector<std::pair<int, int>>> s;
      for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
          if (x != i || y != j) {
            int x3 = i + y - j;
            int y3 = j + i - x;
            int x4 = x + y - j;
            int y4 = y + i - x;
            std::vector<std::pair<int, int>> v = {{i, j}, {x, y}, {x3, y3}, {x4, y4}};
            std::ranges::sort(v);
            if (in(x3, y3) && in(x4, y4)) {
              s.insert(v);
            }
          }
        }
      }
      a.push_back(s.size());
    }
  }

  for (int i = 0; i <= 0; i++) {
    for (int j = 0; j <= m / 2; j++) {
      std::set<std::vector<std::pair<int, int>>> s;
      for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
          if (x != i || y != j) {
            int x3 = i + y - j;
            int y3 = j + i - x;
            int x4 = x + y - j;
            int y4 = y + i - x;
            std::vector<std::pair<int, int>> v = {{i, j}, {x, y}, {x3, y3}, {x4, y4}};
            std::ranges::sort(v);
            if (in(x3, y3) && in(x4, y4)) {
              s.insert(v);
            }
          }
        }
      }
      b.push_back(s.size());
    }
  }
  return std::make_pair(a, b);
}

void solve_bf() {
  int n, m;
  std::cin >> n >> m;
  auto in = [&](int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= m;
  };
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::set<std::vector<std::pair<int, int>>> s;
      for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
          if (x != i || y != j) {
            int x3 = i + y - j;
            int y3 = j + i - x;
            int x4 = x + y - j;
            int y4 = y + i - x;
            std::vector<std::pair<int, int>> v = {{i, j}, {x, y}, {x3, y3}, {x4, y4}};
            std::ranges::sort(v);
            if (in(x3, y3) && in(x4, y4)) {
              s.insert(v);
            }
          }
        }
      }
      std::cout << s.size() << ' ';
    }
    std::cout << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // solve(11, 15);
  solve_bf();

  return 0;
}