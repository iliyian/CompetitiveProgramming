#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  int d = -1;
  for (int i = 1; i <= n; i++) {
    if (d != -1 && a[i] < b[i]) {
      std::cout << "NO\n";
      return;
    }
    if (a[i] < b[i]) {
      d = b[i] - a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] >= b[i] && a[i] - b[i] < d) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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