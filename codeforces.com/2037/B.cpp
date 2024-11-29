#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::multiset<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
  }
  for (int i : s) {
    int t = 1;
    if (i * i == n - 2) t++;
    if ((n - 2) % i == 0 && s.count((n - 2) / i) >= t) {
      std::cout << i << ' ' << (n - 2) / i << '\n';
      return;
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}