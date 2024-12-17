#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a.begin() + 1, a.end());
  std::set<int> s;
  for (int i = n; i >= 1; i--) {
    int l = a[i].first, r = a[i].second;
    if (s.empty() || *s.lower_bound(l) > r) {
      s.insert(l);
    }
  }
  std::cout << s.size() << '\n';
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