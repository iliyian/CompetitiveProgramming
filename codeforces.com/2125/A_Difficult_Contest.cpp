#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = std::ranges::count(str, 'T');
  for (int i = 0; i < n; i++) {
    std::cout << 'T';
  }
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != 'T') {
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