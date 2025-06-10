#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, A, B;
  std::cin >> n >> m >> A >> B;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  if (n * A % 100 || m * B % 100) {
    std::cout << "error\n";
    return;
  }
  int nn = n * A / 100, mm = m * B / 100;
  std::vector<std::vector<char>> b(nn, std::vector<char>(mm));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int si = std::floor(i * A / 100.0), sj = std::floor(j * B / 100.0);
      int ti = std::ceil((i + 1) * A / 100.0), tj = std::ceil((j + 1) * B / 100.0);
      // std::cerr << si << ' ' << sj << ' ' << i << ' ' << j << '\n';
      for (int s = si; s < ti; s++) {
        for (int t = sj; t < tj; t++) {
          if (b[s][t] && b[s][t] != a[i][j]) {
            std::cout << "error\n";
            return;
          }
          b[s][t] = a[i][j];
        }
      }
    }
  }
  for (int i = 0; i < nn; i++) {
    for (int j = 0; j < mm; j++) {
      std::cout << b[i][j];
    }
    std::cout << '\n';
  }
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