#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> str(n + 1);
  std::vector<std::vector<int>> g(3 * n + 1);
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> str[i];
    str[i] = '#' + str[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (str[i][j] == '1') {
        
      }
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