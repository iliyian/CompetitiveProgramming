#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), mx(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  mx[n + 1] = INT_MAX;
  for (int i = n; i >= 1; i--) {
    mx[i] = std::max(mx[i + 1], a[i]);
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