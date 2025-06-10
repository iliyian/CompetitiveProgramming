#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  int cur = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cur += str[i] == '(' ? 1 : -1;
    cnt += cur == 0;
    // std::cout << cur << " \n"[i == n];
  }
  std::cout << (cnt >= 2 ? "YES" : "NO") << '\n';
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