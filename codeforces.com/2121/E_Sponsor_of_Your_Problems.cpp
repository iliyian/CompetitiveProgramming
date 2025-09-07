#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string l, r;
  std::cin >> l >> r;
  for (int i = 0; i < l.size(); i++) {
    if (l[i] != r[i]) {
      if (l[i] == r[i] - 1) {
        std::cout << i * 2 + 1 << '\n';
      } else {
        std::cout << i * 2 << '\n';
      }
      return;
    }
  }
  std::cout << l.size() * 2 << '\n';
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