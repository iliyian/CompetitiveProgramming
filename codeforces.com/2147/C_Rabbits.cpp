#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = "#" + str;
  std::vector<std::array<int, 2>> f(n + 1);
  f[0][1] = f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1') {
      
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