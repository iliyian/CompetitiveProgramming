// date: 2025-05-01 21:37:28
// tag: 弱智题有1900？？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    std::cout << i << ' ' << i << '\n';
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i] / 2;
    int pos = i - x;
    if (pos < 1) pos = i + x;
    std::cout << pos << ' ';
  }
  std::cout << '\n';
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