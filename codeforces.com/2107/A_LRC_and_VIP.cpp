#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int g = 1, mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx = std::max(mx, a[i]);
  }
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[1]) {
      std::cout << "Yes\n";
      for (int i = 1; i <= n; i++) {
        if (a[i] == mx) {
          std::cout << 1 << ' ';
        } else {
          std::cout << 2 << ' ';
        }
      }
      std::cout << '\n';
      return;
    }
  }
  std::cout << "No\n";
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