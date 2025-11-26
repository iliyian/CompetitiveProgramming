#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  int sx = 0, sy = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      std::cin >> ch;
      a[i][j] = (ch == '#');
      if (ch == 'S') {
        sx = i, sy = j;
      }
    }
  }
  std::string s;
  std::cin >> s;
  int x = sx, y = sy;
  std::string NESW = "NESW";
  auto get = [&](int x, int y) -> int {
    if (x < 1 || x > n || y < 1 || y > m) return 1;
    return a[x][y];
  };
  std::vector<std::vector<int>> f(4, std::vector<int>(4, -1));
  std::set<std::array<int, 4>> st;
  auto init = [&]() {
    std::array<int, 4> p = {0, 1, 2, 3};
    do {
      st.insert(p);
    } while (std::next_permutation(p.begin(), p.end()));
  };
  auto update = [&](int d) {
    std::erase_if(st, [&](auto &a) {
      for (int i = 0; i < 4; i++) {
        int _x = x + dx[a[i]], _y = y + dy[a[i]];
        if (a[i] == d) {
          return false;
        }
        if (get(_x, _y) == 0) {
          return true;
        }
      }
      assert(false);
    });
  };
  init();
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int d = NESW.find(s[i]);
    update(d);
    if (st.empty()) {
      init();
      update(d);
      ans++;
    } else {
    }
    x += dx[d], y += dy[d];
  }
  std::cout << ans << '\n';
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