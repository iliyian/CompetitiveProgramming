// date: 2024-11-21 18:59:45
// tag: 关键在于注意到积性

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) n /= i, cnt++;
      ans *= (cnt * 2 + 1);
    }
  }
  if (n > 1) {
    ans *= 3;
  }
  std::cout << (ans + 1) / 2 << '\n';
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