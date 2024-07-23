#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char x;
      std::cin >> x;
      a[i][j] = x - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char x;
      std::cin >> x;
      b[i][j] = x - '0';
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] += a[i][j - 1];
      a[i][j] %= 3;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      a[i][j] += a[i - 1][j];
      a[i][j] %= 3;
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      b[i][j] += b[i][j - 1];
      b[i][j] %= 3;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      b[i][j] += b[i - 1][j];
      b[i][j] %= 3;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i][m] != b[i][m]) {
      std::cout << "NO\n";
      return;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (a[n][i] != b[n][i]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}