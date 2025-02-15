// date: 2025-01-27 23:24:02
// tag: 状压dp，一行高strip，蛇形移动，构造影响作为转移的状态值的改变
// 尾部元素，当前所有元素作为状压dp的二维信息，考虑到操作的单一性将其转化为仅在尾部进行更新
// 就得到了满足的转移方程

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> dis(n, std::vector<int>(m + 1));
  std::vector<std::pair<int, int>> op(m + 1);
  std::vector<int> r(n);
  for (int i = 1; i <= m; i++) {
    int x;
    char ch;
    std::cin >> x >> ch;
    x--;
    op[i] = {x, ch == '+' ? 1 : -1};
    r[x] += ch == '+';
  }
  std::vector<std::vector<int>> f(1 << n, std::vector<int>(n, INT_MAX));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      int mx = 0, cur = 0;
      for (int k = 1; k <= m; k++) {
        if (op[k].first == i && op[k].second == -1) {
          cur--;
        }
        if (op[k].first == j && op[k].second == 1) {
          cur++;
        }
        mx = std::max(mx, cur);
      }
      dis[i][j] = mx + 1;
      // std::cerr << "i,j:" << i + 1 << ' ' << j + 1 << ' ' << dis[i][j] << '\n';
    }
  }
  for (int i = 0; i < n; i++) {
    f[1 << i][i] = 1;
  }
  for (int S = 1; S < (1 << n); S++) {
    for (int j = 0; j < n; j++) {
      if (S >> j & 1) {
        for (int i = 0; i < n; i++) {
          if (S >> i & 1 ^ 1) {
            f[S ^ (1 << i)][i] = std::min(f[S ^ (1 << i)][i], f[S][j] + dis[i][j]);
          }
        }
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    ans = std::min(ans, f[(1 << n) - 1][i] + r[i]);
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