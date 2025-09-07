#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    if (std::abs(a[i] - a[i - 1]) <= 1) {
      std::cout << 0 << '\n';
      return;
    }
  }
  for (int i = 2; i <= n - 1; i++) {
    if (a[i] <= a[i - 1] && a[i] <= a[i + 1] || a[i] >= a[i - 1] && a[i] >= a[i + 1]) {
      std::cout << 1 << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
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