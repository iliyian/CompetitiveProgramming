// date: 2024-08-01 18:42:34
// tag: 构造，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<std::vector<int>> C(100, std::vector<int>(100));
  for (int i = 1; i <= 99; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  int n;
  std::cin >> n;
  if (n <= 3) {
    std::cout << 0 << '\n';
    int t = n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        std::cout << (j > i ? 1 : 0) << ' ';
      }
      std::cout << '\n';
    }
    return 0;
  }

  std::cout << C[n][4] - n * C[(n - 3) / 2][3] << '\n';
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = i % n + 1, t = 1; j != i; j = j % n + 1, t++) {
      f[i][j] = (t < (n - (n - 3) / 2) ? 1 : 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << f[i][j] << " \n"[j == n];
    }
  }

  return 0;
}