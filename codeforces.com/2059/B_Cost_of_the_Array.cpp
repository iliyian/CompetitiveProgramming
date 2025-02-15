#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (k == n) {
    for (int i = 2; i <= n; i += 2) {
      if (a[i] != i / 2) {
        std::cout << i / 2 << '\n';
        return;
      }
    }
    std::cout << n / 2 + 1 << '\n';
    return;
  }
  for (int i = 2; i <= n - k + 2; i++) {
    if (a[i] != 1) {
      std::cout << 1 << '\n';
      return;
    }
  }
  std::cout << 2 << '\n';
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