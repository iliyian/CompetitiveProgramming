// date: 2025-02-15 14:46:50
// tag: 贪心，又是贪心，哎哎哎

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::set<int> s;
  int cur = 0;
  int ans = 0;
  s.insert(0);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cur += a[i];
    if (a[i] == 0 || s.count(cur)) {
      ans++;
      cur = 0;
      s.clear();
      s.insert(0);
    } else {
      s.insert(cur);
    }
  }
  // std::cerr << '\n';
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