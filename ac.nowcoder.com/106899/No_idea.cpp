#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (i <= str.size() - 4 && str[i] == '2' && str[i + 1] == '0' && str[i + 2] == '2' && str[i + 3] == '4') {
      std::cout << 2025;
      i += 3;
    } else {
      std::cout << str[i];
    }
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