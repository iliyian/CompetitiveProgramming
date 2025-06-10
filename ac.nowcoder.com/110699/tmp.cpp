#include <bits/stdc++.h>
#define int long long

void solve() {
  std::mt19937_64 rd(2548280139);
  std::cout << (rd() % 100000000) << '\n';
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