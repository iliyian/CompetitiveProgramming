#include <bits/stdc++.h>
#define int long long

void solve() {
  std::vector<std::pair<int, int>> a(33);
  for (int i = 1; i <= 32; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= 32; i++) {
    if (a[i].second == 1) {
      if (i <= 2) {
        std::cout << 32 << '\n';
      } else if (i <= 6) {
        std::cout << 16 << '\n';
      } else if (i <= 13) {
        std::cout << 8 << '\n';
      } else if (i <= 27) {
        std::cout << 4 << '\n';
      } else if (i <= 31) {
        std::cout << 2 << '\n';
      } else {
        std::cout << 1 << '\n';
      }
      return;
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}