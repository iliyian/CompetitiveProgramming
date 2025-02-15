#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::set<int> a, b;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a.insert(x);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    b.insert(x);
  }
  std::cout << (a.size() + b.size() > 3 ? "YES" : "NO") << '\n';
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