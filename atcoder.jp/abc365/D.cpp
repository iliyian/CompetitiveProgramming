#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;

  str = '#' + str;
  std::string RPS = "RPS";
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(3, LLONG_MIN));
  for (int i = 0; i < 3; i++) {
    if (str[1] == RPS[i]) {
      f[1][i] = 0;
    } else if (str[1] == RPS[(i + 2) % 3]) { // win
      f[1][i] = 1;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      if (str[i] == RPS[(j + 2) % 3]) {
        for (int k = 0; k < 3; k++) {
          if (j != k) {
            f[i][j] = std::max(f[i][j], f[i - 1][k] + 1);
          }
        }
      } else if (str[i] == RPS[j]) {
        for (int k = 0; k < 3; k++) {
          if (j != k) {
            f[i][j] = std::max(f[i][j], f[i - 1][k]);
          }
        }
      }
    }
  }
  std::cout << std::max({f[n][0], f[n][1], f[n][2]}) << '\n';

  return 0;
}