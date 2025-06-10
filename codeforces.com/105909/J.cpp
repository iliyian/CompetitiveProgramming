#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::stack<int> s0, s1;
  std::vector<std::array<int, 2>> ans;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      if (!s1.empty()) {
        s1.pop();
      } else {

      }
    } else {

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