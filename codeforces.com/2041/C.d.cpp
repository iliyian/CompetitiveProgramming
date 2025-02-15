#include <bits/stdc++.h>
#include <random>
// #define int long long

constexpr int N = 12;
// int a[N][N][N], f[N][1 << N][1 << N];

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 12;
  std::cout << n << '\n';
  // std::cin >> n;
  // std::vector a(n, std::vector<std::vector<int>>(n, std::vector<int>(n)));
  // std::vector f(n, std::vector<std::vector<int>>(1 << n, std::vector<int>(1 << n, INT_MAX)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        // std::cin >> a[i][j][k];
        std::cout << std::uniform_int_distribution<>{0, (int)2e7}(rd) << ' ';
      }
      std::cout << '\n';
    }
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