#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, INT_MAX));
  for (int i = 1; i <= n; i++) {
    f[i][i] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      if (a[i] == a[j]) f[i][j] = std::min(f[i + 1][j], f[i][j - 1]);
      for (int k = i; k < j; k++) {
        f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j]);
      }
    }
  }
  std::cout << "&#8238;" << f[1][n] << '\n';

  return 0;
}