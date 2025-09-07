#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 1 << '\n' << 1 << '\n';
    return;
  }
  int i = 0;
  std::vector<std::vector<int>> a(120, std::vector<int>(120));
  for (int j = 29; j >= 0; j--) {
    a[0][j << 2] = n >> j & 1;
  }
  for (int i = 1; i < 120; i++) {
    for (int j = 0; j < 120; j++) {
      if (i == j || i == j + 1 || i == j + 3 && j % 4 == 0) {
        a[i][j] = 1;
      }
    }
  }
  std::cout << 120 << '\n';
  for (int i = 0; i < 120; i++) {
    for (int j = 0; j < 120; j++) {
      std::cout << a[i][j] << ' ';
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