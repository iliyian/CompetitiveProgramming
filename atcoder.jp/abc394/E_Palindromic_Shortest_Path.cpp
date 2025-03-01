// date: 2025-02-24 22:03:01
// tag: 神奇的回文路径生成方式，从中间往两边，观止！

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<char>> a(n, std::vector<char>(n));
  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<int>> ans(n, std::vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) std::cin >> a[i][j];
    ans[i][i] = 0;
    for (int j = 0; j < n; j++) {
      if (a[i][j] != '-' && i != j) {
        q.push({i, j});
        ans[i][j] = 1;
      }
    }
    q.push({i, i});
  }
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][x] == a[y][j] && a[i][x] != '-' && ans[i][j] == -1) {
          assert(a[y][j] != '-');
          ans[i][j] = ans[x][y] + 2;
          q.push({i, j});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << ans[i][j] << ' ';
    }
    std::cout << '\n';
  }
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