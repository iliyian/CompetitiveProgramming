#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<int> f(n + 1, LLONG_MAX / 3);
  f[0] = 0;
  for (int i = 0; i <= n; i++) {
    int p = std::upper_bound(a.begin() + 1, a.end(), a[i] + x) - a.begin() - 1;
    f[p] = std::min(f[p], f[i]);
    p = std::upper_bound(a.begin() + 1, a.end(), a[i] + y) - a.begin() - 1;
    f[p] = std::min(f[p], f[i] + 1);
  }
  std::cout << (f[n] == LLONG_MAX / 3 ? -1 : f[n]) << '\n';
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