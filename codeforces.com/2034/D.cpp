#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::array<int, 3> cnt = {0, 0, 0};
  std::array<std::set<int>, 3> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
    s[a[i]].insert(i);
  }
  for (int i = 1; i <= n; i++) {
    if ()
  }
  std::vector<std::pair<int, int>> ans;
  for (auto [x, y] : ans) {
    std::cout << x << ' ' << y << '\n';
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