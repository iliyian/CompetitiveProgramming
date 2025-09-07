#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(31, LLONG_MAX / 3));
  std::vector<int> is(n + 1);
  f[0][1] = 1;
  f[0][0] = 0;
  for (int i = 2; i <= 30; i++) {
    f[0][i] = std::min({f[0][i - 1] + f[0][i - 2], f[0][i - 1] + f[0][i - 1]}) + 1;
  //  std::cerr << f[0][i] << ' ';
  }
  // std::cerr << '\n';
  // is[0] = 1;
  // std::vector<int> h(n + 1);
  // auto dfs2 = [&](auto self, int u) -> void {
  //   if (u == 0) return;
  //   self(self, l[u]);
  //   self(self, r[u]);
    // h[u] = std::max(h[l[u]], h[r[u]]) + 1;
    // if (std::abs(h[l[u]] - h[r[u]]) <= 1 && is[l[u]] && is[r[u]]) {
    //   f[u][h[u]] = 0;
    //   is[u] = 1;
    // }
  // };
  // dfs2(dfs2, 1);
  auto dfs = [&](auto self, int u) -> void {
    if (u == 0) return;
    self(self, l[u]);
    self(self, r[u]);
    f[u][0] = f[l[u]][0] + f[r[u]][0] + 1;
    f[u][1] = f[l[u]][0] + f[r[u]][0]; 
    for (int i = 2; i <= 30; i++) {
      f[u][i] = std::min({f[u][i],
        f[l[u]][i - 2] + f[r[u]][i - 1],
        f[l[u]][i - 1] + f[r[u]][i - 2],
        f[l[u]][i - 1] + f[r[u]][i - 1]});
    }
  };
  dfs(dfs, 1);
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << h[i] << ' ';
  // }
  // std::cerr << '\n';
  // std::cerr << '\n';
//  for (int i = 1; i <= n; i++) {
//    for (int j = 0; j <= 5; j++) {
//      std::cerr << f[i][j] << ' ';
//    }
//    std::cerr << '\n';
//  }
  int ans = LLONG_MAX / 3;
  for (int i = 0; i <= 30; i++) {
	  // std::cout << f[1][i] << ' ';
    ans = std::min(ans, f[1][i]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("d.in", "r", stdin);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
