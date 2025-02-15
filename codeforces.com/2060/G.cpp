// date: 2025-01-20 11:34:56
// tag: 线性dp，推性质

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return a[x] + b[x] < a[y] + b[y];
  });
  std::vector<std::array<int, 4>> f(n + 1, {0});
  // 偶未，偶已，奇未，奇已
  f[p[1]][0] = 1;
  f[p[1]][3] = 1;
  auto check = [&](int x, int y, bool f) {
    return (f ? a[x] <= b[y] && b[x] <= a[y] : a[x] <= a[y] && b[x] <= b[y]);
  };
  for (int i = 2; i <= n; i++) {
    bool f0 = check(p[i - 1], p[i], 0), f1 = check(p[i - 1], p[i], 1);
    f[p[i]][0] |= f0 && f[p[i - 1]][0];
    f[p[i]][0] |= f1 && f[p[i - 1]][1];

    f[p[i]][1] |= f1 && f[p[i - 1]][2];
    f[p[i]][1] |= f0 && f[p[i - 1]][3];

    f[p[i]][2] |= f0 && f[p[i - 1]][2];
    f[p[i]][2] |= f1 && f[p[i - 1]][3];

    f[p[i]][3] |= f1 && f[p[i - 1]][0];
    f[p[i]][3] |= f0 && f[p[i - 1]][1];
  }
  std::cout << (f[p[n]][0] || f[p[n]][1] ? "YES" : "NO") << '\n';
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