#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::string s;
  std::cin >> n >> s;
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == '.' && s[i - 1] == '#' && s[i + 1] == '#') {
      ans++;
    }
  }
  std::cout << ans << '\n';
  return 0;
}