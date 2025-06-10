#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != '9' && i < str.size() - 1) {
      for (int j = 0; j < str.size() - 1; j++) {
        std::cout << 9;
      }
      return;
    }
  }
  std::cout << str;
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