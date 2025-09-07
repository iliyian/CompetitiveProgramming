#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  if (str[0] == str[2]) {
    std::cout << "No\n";
  } else {
    if (str[1] == '-') {
      if (str[0] == '0') {
        std::cout << "Yes\n";
      } else {
        std::cout << "No\n";
      }
    } else {
      std::cout << "Yes\n";
    }
  }
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