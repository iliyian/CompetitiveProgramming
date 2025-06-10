#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s;
  std::cin >> s;
  if (s.size() == 3) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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