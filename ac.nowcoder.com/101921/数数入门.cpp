#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= i; j++) {
      if (a[i][j] > a[i + 1][j] || a[i][j] > a[i + 1][j + 1]) {
        std::cout << "No\n";
        return;
      }
    }
  }
  std::cout << "Yes\n";
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