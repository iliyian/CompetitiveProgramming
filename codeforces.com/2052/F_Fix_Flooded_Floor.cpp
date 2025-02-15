// date: 2025-01-24 16:32:30
// tag: 贪心

#include <bits/stdc++.h>
#include <cerrno>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(2, std::vector<int>(n + 2));
  int cnt = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      std::cin >> ch;
      a[i][j] = ch == '#';
      cnt += a[i][j];
    }
  }
  a[0][0] = a[1][0] = a[0][n + 1] = a[1][n + 1] = 1;
  // for (int i = 1; i <= n; i++) {
  //   for (int t = 0; t < 2; t++) {
  //   }
  // }
  if (cnt % 2) {
    std::cout << "None\n";
    return;
  }
  bool f = false;
  for (int i = 1; i <= n; i++) {
    for (int t = 0; t < 2; t++) {
      if (!a[t][i] && a[t ^ 1][i] && a[t][i - 1]) {
        if (a[t][i + 1]) {
          std::cout << "None\n";
          return;
        }
        a[t][i + 1] = a[t][i] = 1;
      }
      if (!a[t][i] && a[t][i - 1] && a[t][i + 1]) {
        if (a[t ^ 1][i]) {
          std::cout << "None\n";
          return;
        }
        a[t][i] = a[t ^ 1][i] = 1;
      }
      if (!a[0][i] && !a[0][i + 1] && !a[1][i] && !a[1][i + 1]) {
        a[0][i] = a[0][i + 1] = a[1][i] = a[1][i + 1] = 1;
        // std::cout << "Multiple\n";
        f = true;
        // return;
      }
    }
  }
  std::cout << (f ? "Multiple" : "Unique") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}