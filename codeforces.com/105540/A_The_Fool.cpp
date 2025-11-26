#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::string>> a(n + 1, std::vector<std::string>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int t = 0; t < k; t++) {
        char c;
        std::cin >> c;
        a[i][j].push_back(c);
      }
    }
  }
  std::string s = a[1][1];
  int cnt = 0, ansi = 0, ansj = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != s) {
        cnt++;
        ansi = i, ansj = j;
      }
    }
  }
  if (cnt == 1) {
    std::cout << ansi << ' ' << ansj << '\n';
  } else {
    std::cout << 1 << ' ' << 1 << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}