// date: 2024-08-15 15:35:52
// tag: 区间dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, INT_MAX));
  for (int i = 1; i <= n; i++) {
    f[i][i] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j] - (str[k] == str[j]));
      }
    }
  }
  std::cout << f[1][n] << '\n';

  return 0;
}