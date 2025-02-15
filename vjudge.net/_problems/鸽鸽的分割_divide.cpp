// date: 2025-02-10 14:11:58
// tag: 神秘找规律题，可以发现三阶差分是等差数列

#include <bits/stdc++.h>
#define int long long

std::vector<std::vector<int>> a(4, std::vector<int>(65));

void solve(int n) {
  if (n == 0) {
    std::cout << 1 << '\n';
    return;
  }
  std::cout << a[3][n] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= 64; i++) {
    a[0][i] = i;
  }
  a[1][1] = a[2][1] = a[3][1] = 1;
  for (int i = 1; i <= 3; i++) {
    for (int j = 2; j <= 64; j++) {
      a[i][j] = a[i][j - 1] + a[i - 1][j - 1];
      // std::cerr << a[i][j] << ' ';
    }
    // std::cerr << '\n';
  }

  int t = 1;
  // std::cin >> t;
  int n;
  while (std::cin >> n) {
    solve(n);
  }
  return 0;
}