#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = a[i] - a[i - 1];
  }
  sum = a[1] - a[n];
  std::sort(b.begin() + 2, b.end());
  for (int i = 3; i <= n; i++) {
    // std::cerr << b[i] << '\n';
    b[i] += b[i - 1];
  }
  b[1] = 0;
  int q;
  std::cin >> q;
  while (q--) {
    int op, x;
    std::cin >> op >> x;
    if (op == 1) {
      std::cout << sum + b[x] << '\n';
    }
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