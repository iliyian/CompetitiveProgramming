// date: 2024-09-12 17:23:46
// tag: 整数概率公式 \E(x)=\sum_{i=1}^{\inf}{\P(i<=x)}
// 树形期望dp

#include <bits/stdc++.h>
#define int long long

signed main() {
  int q, n;
  std::cin >> q >> n;
  if (q == 1) {
    std::vector<double> f(n + 1);
    for (int i = 2; i <= n; i++) {
      f[i] = f[i - 1] + 2.0 / i;
    }
    std::cout << std::fixed << std::setprecision(6) << f[n] << '\n';
  } else {
    std::vector<std::vector<double>> f(n + 1, std::vector<double>(n + 1));
    // 深度>=j，共i个叶的概率
    for (int i = 1; i <= n; i++) {
      f[i][0] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i - 1; j++) {
        for (int k = 1; k <= i - 1; k++) {
          f[i][j] +=
              (f[k][j - 1] + f[i - k][j - 1] - f[k][j - 1] * f[i - k][j - 1]) /
              (i - 1);
        }
      }
    }
    double ans = 0;
    for (int i = 1; i < n; i++) {
      ans += f[n][i];
    }
    std::cout << std::fixed << std::setprecision(6) << ans << '\n';
  }
}