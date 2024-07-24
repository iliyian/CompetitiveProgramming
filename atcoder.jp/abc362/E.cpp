#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector<std::vector<std::vector<int>>> f(n + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1)));
  std::vector<int> ans(n + 1);

  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (len == 2) {
          f[i][j][len] = 1;
        } else {
          for (int k = j + 1; k <= n; k++) {
            if (a[j] - a[i] == a[k] - a[j]) {
              f[j][k][len] += f[i][j][len - 1];
            }
          }
        }
      }
    }
  }

  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ans[len] += f[i][j][len];
      }
    }
  }

  ans[1] = n;
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }

  return 0;
}