#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> b(n + 1), c(n + 1);
  int mn = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    b[i] = std::max(b[i], b[i - 1]);
    mn += b[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  mx += c[n];
  for (int i = n - 1; i >= 1; i--) {
    c[i] = std::min(c[i], c[i + 1]);
    mx += c[i];
  }
  // std::cerr << mn << ' ' << mx << '\n';
  std::cout << (mn <= m && m <= mx ? "YES" : "NO") << '\n';
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