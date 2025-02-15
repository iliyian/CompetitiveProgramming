#include <bits/stdc++.h>
#define int long long

int C[51][51];

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (n == 1) {
    std::cout << a[1] << '\n';
    return;
  }
  int ans = LLONG_MIN;
  for (int i = 1; i <= n; i++) {
    auto b = a;
    if (i != 1) {
      ans = std::max(ans, std::abs(std::accumulate(a.begin(), a.end(), 0ll)));
    } else {
      ans = std::max(ans, std::accumulate(a.begin(), a.end(), 0ll));
    }
    // for (auto j : b) {
    //   std::cerr << j << ' ';
    // }
    // std::cerr << '\n';
    for (int j = 2; j < b.size(); j++) {
      b[j - 1] = a[j] - a[j - 1];
    }
    b.pop_back();
    a = b;
  }
  // std::cout << ans << '\n';
  std::cout << ans << '\n';
  // std::cout << std::max(ans, a[1]) << '\n';
  // int ans = 0;
  // for (int i = 1; n - i + 1 >= i; i++) {
  //   ans += ((i - 1) % 2 == 1 ? 1 : -1) * C[n - 1][i - 1] * (a[i] + (i == n - i + 1 ? 0 : a[n - i + 1]));
  // }
  // if (n == 1) {
  //   std::cout << a[1] << '\n';
  //   return;
  // }
  // std::cout << std::max({std::abs(ans), a[n] - a[1], a[1] - a[n]}) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  C[0][0] = 1;
  for (int i = 1; i <= 50; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}