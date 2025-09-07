#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s;
  std::cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += (s[i] - '0') << (s.size() - i - 1);
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