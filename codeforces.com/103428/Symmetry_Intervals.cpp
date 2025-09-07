#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  while (q--) {
    std::string t;
    int a;
    std::cin >> t >> a;
    t = '#' + t;
    int ans = 0, len = 0;
    for (int i = a; i - a + 1 < t.size(); i++) {
      if (t[i - a + 1] == str[i]) {
        len++;
      } else {
        ans += len * (len + 1) / 2;
        len = 0;
      }
    }
    ans += len * (len + 1) / 2;
    std::cout << ans << '\n';
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