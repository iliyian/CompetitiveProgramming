// date: 2024-08-07 13:27:02
// tag: 状压概率dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::vector<double>> a(n, std::vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<double> f(1 << n);
  f[(1 << n) - 1] = 1;
  for (int s = (1 << n) - 1; s > 0; s--) {
    for (int i = 0; i < n; i++) {
      if (s >> i & 1) {
        int cnt = __builtin_popcount(s);
        for (int j = 0; j < n; j++) {
          if (s >> j & 1 ^ 1) {
            f[s] += f[s | 1 << j] * a[i][j] / ((cnt + 1) * cnt / 2);
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << std::fixed << std::setprecision(20) << f[1 << i] << ' ';
  }
  std::cout << '\n';

  return 0;
}