#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  int ans = 0;
  auto check = [&](int x, int y) {
    if (x < 1 || x > n - 1 || y < 1 || y > n - 1) return false;
    int b[4] = {a[x][y], a[x + 1][y], a[x][y + 1], a[x + 1][y + 1]};
    std::sort(b, b + 4);
    return std::unique(b, b + 4) - b >= 3;
  };
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= n - 1; j++) {
      ans += check(i, j);
    }
  }
  int ini = ans;
  for (int i = 1; i <= n ; i++) {
    for (int j = 1; j <= n; j++) {
      int cur = ini;
      cur -= check(i - 1, j - 1) + check(i - 1, j) + check(i, j - 1) + check(i, j);
      std::vector<int> v;
      // std::cerr << cur << '\n';
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx || dy) {
            if (i + dx >= 1 && i + dx <= n && j + dy >= 1 && j + dy <= n) {
              int c = a[i + dx][j + dy];
              int t = a[i][j];
              a[i][j] = c;
              v.push_back(c);
  
              cur += check(i - 1, j - 1) + check(i - 1, j) + check(i, j - 1) + check(i, j);
              ans = std::max(ans, cur);
              cur -= check(i - 1, j - 1) + check(i - 1, j) + check(i, j - 1) + check(i, j);
  
              a[i][j] = t;
            }
          }
        }
      }

      std::sort(v.begin(), v.end());
      v.erase(std::unique(v.begin(), v.end()), v.end());
      int c = 1;
      while (c <= std::min<int>(v.size(), k) && v[c - 1] == c) c++;
      if (c <= k) {
        int t = a[i][j];
        a[i][j] = c;

        cur += check(i - 1, j - 1) + check(i - 1, j) + check(i, j - 1) + check(i, j);
        // std::cerr << check(i - 1, j - 1) << ' ' << check(i - 1, j) << ' ' << check(i, j - 1) << ' ' << check(i, j) << ' ';
        // std::cerr << cur << '\n';
        ans = std::max(ans, cur);
        cur -= check(i - 1, j - 1) + check(i - 1, j) + check(i, j - 1) + check(i, j);

        a[i][j] = t;
      }
    }
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