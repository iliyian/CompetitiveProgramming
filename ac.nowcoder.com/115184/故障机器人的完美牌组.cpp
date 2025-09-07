#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int mx = 1;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (i) {
      if (a[i] > a[mx]) {
        mx = i;
      }
    }
  }
  if (a[mx] == 0) {
    std::cout << n << '\n';
    for (int i = 0; i < n; i++) {
      std::cout << a[i] << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << n - 1 << '\n';
    std::cout << a[0] + a[mx] << ' ';
    for (int i = 1; i < n; i++) {
      if (i != mx) {
        std::cout << a[i] << ' ';
      }
    }
    std::cout << '\n';
  }
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