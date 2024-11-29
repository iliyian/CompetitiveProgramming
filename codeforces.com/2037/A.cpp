#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::set<int> s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (s.count(x)) {
      s.erase(x);
      ans++;
    } else {
      s.insert(x);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}