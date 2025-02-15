#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == '@' && m-- > 0) {
      str[i] = '.';
    }
  }
  std::cout << str << '\n';
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