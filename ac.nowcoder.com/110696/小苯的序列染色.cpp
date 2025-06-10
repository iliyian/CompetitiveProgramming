#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  if (n <= 2 && str.find('1') != str.npos) {
    std::cout << "NO\n";
    return;
  }
  if (str.back() == '1') {
    std::cout << "NO" << '\n';
    return;
  }
  if (str[0] == '1' && str[1] == '0') {
    std::cout << "NO\n";
    return;
  }
  for (int i = 1; i < n - 1; i++) {
    if (str[i] == '1' && str[i - 1] == '1') break;
    if (str[i] == '1' && str[i - 1] != '1' && str[i + 1] != '1') {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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