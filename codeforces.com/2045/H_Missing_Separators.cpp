#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, LLONG_MAX / 3));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
          
    }
  }
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