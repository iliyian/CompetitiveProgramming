#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size(); i++) {
    int x = str[i] - '0';
    if (x >> 2 & 1) std::cout << "r";
    else std::cout << "-";
    if (x >> 1 & 1) std::cout << "w";
    else std::cout << "-";
    if (x >> 0 & 1) std::cout << "x";
    else std::cout << "-";
  }
  std::cout << '\n';
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