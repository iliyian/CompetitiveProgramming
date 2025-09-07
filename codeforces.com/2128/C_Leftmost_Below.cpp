#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int mn = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > 2 * mn - 1) {
      std::cout << "NO\n";
      return;
    }
    mn = std::min(mn, a[i]);
  }
  std::cout << "YES\n";
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