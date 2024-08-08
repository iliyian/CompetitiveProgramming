// date: 2024-08-07 12:59:54
// tag: 期望的期望dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<double> len(n + 1), f(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
    len[i] = (len[i - 1] + 1) * p[i];
    f[i] = f[i - 1] + p[i] * (2 * len[i - 1] + 1);
  }
  std::cout << std::fixed << std::setprecision(20) << f[n] << '\n';

  return 0;
}