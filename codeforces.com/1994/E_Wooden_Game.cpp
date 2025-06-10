// date: 2025-03-25 14:40:38
// tag: 什么神仙诈骗题，只要观察到对每棵树都可以或上[1,siz]，就可以直接按位贪了，顺便又是经典的按位贪的位运算套路

#include <bits/stdc++.h>
#define int long long

void solve() {
  int k;
  std::cin >> k;
  std::multiset<int> s;
  for (int i = 1; i <= k; i++) {
    int n;
    std::cin >> n;
    s.insert(n);
    for (int j = 2; j <= n; j++) {
      int y;
      std::cin >> y;
    }
  }
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (*std::prev(s.end()) >= (1ll << i)) {
      ans += 1ll << i;
      int x = *(--s.end());
      s.erase(--s.end());
      x -= 1ll << i;
      s.insert(x);
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