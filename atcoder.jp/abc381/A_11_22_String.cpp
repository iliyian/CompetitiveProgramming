#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int i = 0;
  if (str.size() % 2 == 0) {
    std::cout << "No\n";
    return;
  }
  while (i < (str.size() + 1) / 2 - 1) {
    if (str[i++] != '1') {
      std::cout << "No\n";
      return;
    }
  }
  if (str[i++] != '/') {
    std::cout << "No\n";
    return;
  }
  while (i < str.size()) {
    if (str[i++] != '2') {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
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