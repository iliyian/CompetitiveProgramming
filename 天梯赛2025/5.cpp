#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int val[128] {}, cnt[128] {};
  int ans = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    std::cin >> val[i];
  }
  for (int i = 0; i < str.size(); i++) {
    ans += val[str[i]];
    cnt[str[i]]++;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    std::cout << cnt[i] << " \n"[i == 'z'];
  }
  std::cout << ans;
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