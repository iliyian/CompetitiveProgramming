#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::array<int, 3>> val;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      val.push_back({a[i][j], i, j});
    }
  }
  std::sort(val.begin(), val.end(), std::greater<>());
  std::vector<int> visr(n + 1), visc(m + 1);
  for (auto [w, x, y] : val) {
    if (visr[x] || visc[y]) continue;
    visr[x] = visc[y] = 1;
    if (!--k) break;
  }
  int lstunvis = m;
  while (visc[lstunvis]) lstunvis--;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!visr[i] && !visc[j]) {
        std::cout << a[i][j] << " \n"[j == lstunvis];
      }
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}