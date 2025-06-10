#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, s, v;
  std::cin >> n >> s >> v;
  std::cout << (n <= s * v ? 1 : 0) << '\n';
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