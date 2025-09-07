#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    p[i] = i;
  }
  std::ranges::sort(p, [&](auto x, auto y) {
    return a[x] < a[y];
  });
  auto b = a;
  std::vector<int> rp(n);
  for (int i = 0; i < n; i++) {
    rp[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i] = b[p[i]];
  }
  std::vector<int> g(n);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    // g[x].push_back(y);
    g[rp[y]] |= 1 << rp[x];
  }
  std::vector<int> f(1 << n, LLONG_MAX / 3);
  f[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (f[i] != LLONG_MAX / 3) {
      int now = 0;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) continue;
        if ((i & g[j]) != g[j]) continue;
        now |= 1 << j;
        f[i | now] = std::min(f[i | now], f[i] + a[j]);
      }
    }
  }
  std::cout << f[(1 << n) - 1] << '\n';
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