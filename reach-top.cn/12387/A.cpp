#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  std::string a;
  std::cin >> a;
  int ans = 0;
  for (char c : a) ans += c - '0';
  std::reverse(a.begin(), a.end());
  std::cout << ans << '\n' << a << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}