// date: 2024-12-02 00:38:40
// tag: 似乎将区间等分的一系列题目都可以考虑考虑根号分治？
// 和除法有关的，间隔一端进行询问和操作的

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  constexpr int B = 400;
  std::vector<std::vector<int>> b(B + 1, std::vector<int>(B + 1));
  for (int i = 1; i <= n; i++) {
    for (int mod = 1; mod <= B; mod++) {
      b[mod][i % mod] += a[i];
    }
  }
  for (int i = 1; i <= m; i++) {
    char op;
    int x, y;
    std::cin >> op >> x >> y;
    if (op == 'A') {
      if (x <= B) {
        std::cout << b[x][y] << ' ';
      } else {
        int ans = 0;
        for (int k = 0; k * x + y <= n; k++) {
          ans += a[k * x + y];
        }
        std::cout << ans << ' ';
      }
      std::cout << '\n';
    } else {
      for (int mod = 1; mod <= B; mod++) {
        b[mod][x % mod] += y - a[x];
      }
      a[x] = y;
    }
  }
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