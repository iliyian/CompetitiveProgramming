#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r < n; r++) {
      int x = a[l] % 3, y = (a[r] - a[l]) % 3, z = (a[n] - a[r]) % 3;
      if (x == y && x == z || (x != y && y != z && x != z)) {
        std::cout << l << ' ' << r << '\n';
        return;
      }
    }
  }
  std::cout << 0 << ' ' << 0 << '\n';
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