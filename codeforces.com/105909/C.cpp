#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k, x;
  std::cin >> n >> m >> k >> x;
  std::vector<__int128> b(n + 1), c(n + 1);
  std::vector<int> p(n + 1);
  __int128 l = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    int x, y;
    std::cin >> x >> y;
    b[i] = x, c[i] = y;
    r += b[i] * c[i];
  }
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return c[x] - k * b[x] > c[y] - k * b[y];
  });
  for (int i = 1; i <= n; i++) {
    __int128 v;
    if (m >= x) {
      v = x;
      m -= x;
    } else {
      v = m;
      m = 0;
    }
    l += k * v * v + v * (c[p[i]] - k * b[p[i]]);
  }
  // std::cerr << l << ' ' << r << '\n';
  std::cout << (l > r ? "YES" : "NO") << '\n';
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