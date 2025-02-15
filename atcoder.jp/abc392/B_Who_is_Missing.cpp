#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::set<int> s;
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
  }
  std::cout << n - s.size() << '\n';
  for (int i = 1; i <= n; i++) {
    if (!s.count(i)) {
      std::cout << i << ' ';
    }
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