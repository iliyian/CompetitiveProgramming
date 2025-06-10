#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  if (a == b && a == c && a == d) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
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