#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n % 2 == 0) {
    std::cout << -1 << '\n';
    return;
  }
  int now = 0;
  for (int i = 1; i <= n; i++) {
    std::cout << now + 1 << ' ';
    now = (now + 2) % n;
  }
  std::cout << '\n';
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