#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] -= i;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  std::multiset<int> s1, s2;
  auto add = [&](int x) {
    if (s1.empty()) s1.insert(x);
    if (s2.empty()) s2
  };
  for (int i = 1, j = 1; i <= n; i++) {
    if (s1.empty()) s1.insert(a[i]);
    else if 9
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