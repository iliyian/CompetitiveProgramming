// date: 2025-03-20 09:26:59
// tag: 神奇贪心，分牌问题，只考虑充分性暴力判断

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int sum = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx = std::max(mx, a[i]);
    sum += a[i];
  }
  for (int i = n; i >= 1; i--) {
    if ((sum + k) / i * i >= sum && (sum + k) / i >= mx) {
      std::cout << i << '\n';
      return;
    }
  }
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