// date: 2024-12-20 16:22:32
// tag: 构造，图论，无向图要么是环，要么是树

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  if (m > n * 2 - 1) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  std::vector<std::vector<int>> ans(n * 2 + 1, std::vector<int>(m + 1));
  int c = 1;
  for (int i = 1; i <= m; i++) {
    int x = i;
    int y = x % (n * 2) + 1;
    // std::cout << x << ' ' << y << '\n';
    for (int j = 1; j <= n; j++) {
      ans[x][i] = ans[y][i] = j;
      x = y % (n * 2) + 1;
      y = x % (n * 2) + 1;
    }
  }
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << ans[i][j] << ' ';
    }
    std::cout << '\n';
  }
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
