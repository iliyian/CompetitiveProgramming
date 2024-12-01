#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      if (a[i + 1] == i && a[i] == i + 1) {
        std::swap(a[i], a[i + 1]);
      } else {
        std::cout << "NO\n";
        return;
      }
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