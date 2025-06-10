#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int ans = 0;
  bool f = false;
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] == '0') {
      if (!f) ans++;
    } else {
      if (!f) f = true;
      else ans++;
    }
  }
  std::cout << ans << '\n';
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