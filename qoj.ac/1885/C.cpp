#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    mx = std::max(mx, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == mx) {
      std::cout << i + 1 << ' ';
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}