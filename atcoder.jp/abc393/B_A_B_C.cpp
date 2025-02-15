#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      for (int k = j + 1; k < str.size(); k++) {
        if (k - j == j - i && str[i] == 'A' && str[j] == 'B' && str[k] == 'C') {
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