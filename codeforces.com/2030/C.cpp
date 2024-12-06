#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  for (int i = 1; i < n; i++) {
    if (str[i] == '1' && str[i + 1] == '1') {
      std::cout << "YES\n";
      return;
    }
  }
  if (str[1] == '1' || str[n] == '1') {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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