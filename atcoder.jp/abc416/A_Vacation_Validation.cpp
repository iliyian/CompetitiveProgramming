#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, l, r;
  std::string str;
  std::cin >> n >> l >> r >> str;
  std::cout << (std::count(str.begin() + l - 1, str.begin() + r - 1 + 1, 'o') == (r - l + 1) ? "Yes" : "No") << '\n';
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