#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::set<int> s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (!s.count(a[i])) {
      ans++;
      s.insert(a[i]);
    }
    while (!s.empty() && *s.rbegin() > a[i]) {
      s.erase(--s.end());
    }
  }
  std::cout << ans << ' ';
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