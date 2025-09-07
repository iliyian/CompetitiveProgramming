#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    auto s = std::to_string(n);
    auto t = s;
    std::ranges::reverse(t);
    if (s == t) {
      std::cout << s << ' ' << i << '\n';
      return;
    }
    if (i == k) break;
    int sum = std::stoll(s) + std::stoll(t);
    n = sum;
  }
  std::cout << n << ' ' << -1 << '\n';
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