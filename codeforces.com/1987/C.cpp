#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), f(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  f[n] = a[n];
  int ans = f[n];
  for (int i = n - 1; i >= 1; i--) {
    f[i] = std::max(f[i + 1] + 1, a[i]);
    ans = std::max(f[i], a[i]);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}