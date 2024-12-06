#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;
constexpr int mod = 1e9 + 7;

std::vector<int> p(N + 1);

void solve() {
  // std::vector<std::vector<int>> C(10, std::vector<int>(10));
  // int N = 10;
  // for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
  //   C[n][0] = 1;
  //   C[n][n] = 1;
  //   for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
  //     C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
  //   for (int k = 0; k <= n; k++) {
  //     std::cout << C[n][k] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i] || b[i] == 0) {
      std::cout << 0 << '\n';
    } else {
      std::cout << p[b[i]] << '\n';
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  p[0] = 1;
  for (int i = 1; i <= N; i++) {
    p[i] = p[i - 1] * 2 % mod;
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}