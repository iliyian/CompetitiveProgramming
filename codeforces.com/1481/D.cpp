// date: 2024-09-05 20:30:45
// tag: 分类讨论，构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  if (m == 1) {
    std::cout << "YES\n";
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }
  bool f = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && a[i][j] == a[j][i]) {
        std::cout << "YES\n";
        for (int k = 0; k <= m; k++) {
          std::cout << (k & 1 ? i + 1 : j + 1) << ' ';
        }
        std::cout << '\n';
        return;
      }
    }
  }
  if (m & 1) {
    std::cout << "YES\n";
    for (int i = 0; i <= m; i++) {
      std::cout << (i & 1 ? 1 : 2) << ' ';
    }
    std::cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (a[i][j] == 'a' && a[j][k] == 'a') {
          i++, j++, k++;
          std::cout << "YES\n";
          if (m % 4 == 0) {
            for (int t = 0; t < m; t += 4) {
              std::cout << j << ' ' << i << ' ' << j << ' ' << k << ' ';
            }
            std::cout << j << ' ';
          } else {
            std::cout << i << ' ' << j << ' ';
            for (int t = 2; t < m; t += 4) {
              std::cout << k << ' ' << j << ' ' << i << ' ' << j << ' ';
            }
            std::cout << k << ' ';
          }
          std::cout << '\n';
          return;
        }
      }
    }
  }
  std::cout << "NO\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}