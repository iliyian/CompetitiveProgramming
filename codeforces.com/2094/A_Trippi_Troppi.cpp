#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a.front() << b.front() << c.front() << '\n';
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