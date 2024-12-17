#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    auto p = std::lower_bound(a.begin() + 1, a.end(), i);
    if (p == a.end() || *p == i) {
      s.insert(i);
    }
  }
  int len = s.size();
  std::vector<int> req(len);
  auto prv = 0;
  for (int i = 0; i < len; i++) {
    auto p = std::lower_bound()
  }
  for (int m = n; m >= 1; m--) {
    
  }
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