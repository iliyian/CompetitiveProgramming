#include <bits/stdc++.h>
#define int long long

void solve() {
  int a[6];
  for (int i = 1; i <= 5; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= 4; i++) {
    std::swap(a[i], a[i + 1]);
    if (std::is_sorted(a + 1, a + 6)) {
      std::cout << "Yes\n";
      return;
    }
    std::swap(a[i], a[i + 1]);
  }
  std::cout << "No\n";
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