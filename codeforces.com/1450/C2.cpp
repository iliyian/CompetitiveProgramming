// date: 2024-12-09 22:00:38
// tag: 基于总和的操作最小化的鸽巢原理，构造

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<char>> a(n + 1, std::vector<char>(n + 1));
  std::array<std::array<int, 2>, 3> cnt = {};
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
      if (a[i][j] != '.') {
        tot++;
        cnt[(i + j) % 3][a[i][j] == 'X']++;
      }
    }
  }
  int mn = INT_MAX, idx = 0, c = 0;
  for (int i = 0; i < 3; i++) {
    if (cnt[i][0] + cnt[(i + 1) % 3][1] < mn) {
      mn = cnt[i][0] + cnt[(i + 1) % 3][1];
      idx = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int now = (i + j) % 3;
      if (now == idx && a[i][j] == 'O') {
        a[i][j] = 'X';
        c++;
      }
      if (now == (idx + 1) % 3 && a[i][j] == 'X') {
        a[i][j] = 'O';
        c++;
      }
      std::cout << a[i][j];
    }
    std::cout << '\n';
  }
  // std::cout << c << ' ' << tot << '\n';
  // assert(c * 3 <= tot);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
