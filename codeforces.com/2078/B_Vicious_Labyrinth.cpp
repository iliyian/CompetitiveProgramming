#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (k % 2) {
    for (int i = 1; i <= n - 2; i++) {
      std::cout << n << ' ';
    }
  } else {
    for (int i = 1; i <= n - 2; i++) {
      std::cout << n - 1 << ' ';
    }
  }
  std::cout << n << ' ' << n - 1 << '\n';
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