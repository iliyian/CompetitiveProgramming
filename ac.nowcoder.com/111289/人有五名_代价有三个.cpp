#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<int> v5, v3;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '5') {
      v5.push_back(i);
    } else if (str[i] == '3') {
      v3.push_back(i);
    }
  }
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r <= n; r++) {
      auto p = std::lower_bound(v5.begin(), v5.end(), l) - v5.begin();
      if (p != v5.size() && v5[p] <= r) {
        auto q = std::lower_bound(v3.begin(), v3.end(), v5[p]) - v3.begin();
        if (q != v3.size() && v3[q] <= r) {
          ans++;
        }
      }
    }
  }
  std::cout << ans << '\n';
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