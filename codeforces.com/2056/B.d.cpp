#include <bits/stdc++.h>
#include <random>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 30;
  // std::cin >> n;
  std::vector<int> a(n + 1);
  std::iota(a.begin(), a.end(), 0);
  std::shuffle(a.begin() + 1, a.end(), rd);
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      auto p = std::find(a.begin(), a.end(), i);
      auto q = std::find(a.begin(), a.end(), j);
      if (p < q) b[i][j] = b[j][i] = 1;
    }
  }
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << b[i][j] << ' ';
    }
    std::cout << '\n';
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}