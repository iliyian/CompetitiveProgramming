#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string ok;
  std::cin >> ok;
  std::string cur;
  for (int i = 0; i < ok.size(); i++) {
    if (ok[i] == 'O') {
      std::cout << ".-.-";
    } else {
      std::cout << ".-";
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