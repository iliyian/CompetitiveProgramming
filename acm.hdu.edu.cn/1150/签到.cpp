#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string name;
  std::cin >> n >> name;
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    if (str == name) {
      ans = i;
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