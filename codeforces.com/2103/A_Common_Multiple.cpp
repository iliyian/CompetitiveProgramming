#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
  }
  std::cout << s.size() << '\n';
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