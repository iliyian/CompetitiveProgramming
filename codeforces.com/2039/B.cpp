#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  if (str.size() == 1) {
    std::cout << -1 << '\n';
    return;
  }
  if (str.size() == 2) {
    if (str.front() == str.back()) {
      std::cout << str << '\n';
    } else {
      std::cout << -1 << '\n';
    }
    return;
  }
  for (int i = 0; i < str.size() - 1; i++) {
    if (str[i] == str[i + 1]) {
      std::cout << str[i] << str[i + 1] << '\n';
      return;
    }
  }
  for (int i = 0; i < str.size() - 2; i++) {
    if (str[i] != str[i + 1] && str[i] != str[i + 2]) {
      std::cout << str.substr(i, 3) << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
  // std::cout << str.substr(0, 3) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}