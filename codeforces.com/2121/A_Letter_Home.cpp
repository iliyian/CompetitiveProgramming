#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, s, l = LLONG_MAX, r = LLONG_MIN;
  std::cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    l = std::min(l, x);
    r = std::max(r, x);
  }
  std::cout << std::min(std::abs(s - l), std::abs(s - r)) + r - l << '\n';
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