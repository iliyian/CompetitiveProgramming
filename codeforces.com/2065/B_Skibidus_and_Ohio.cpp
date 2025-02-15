#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size() - 1; i++) {
    if (str[i] == str[i + 1]) {
      std::cout << 1 << '\n';
      return;
    }
  }
  std::cout << str.size() << '\n';
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