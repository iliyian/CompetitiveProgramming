#include <bits/stdc++.h>
#define int long long

std::vector<int> f(32);
std::vector<std::array<int, 2>> g(32), h(32);

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int k = 63 - __builtin_clzll(i);
    for (int j = k; j >= 0; j--) {
      int t = k - j + 1;
      if (i >> j & 1 && t % 2 == 1) {
        ans++;
      }
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("I.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  f[1] = 1, g[1] = {0, 1};
  for (int i = 2; i <= 30; i++) {
    f[i] = f[i - 1] * 2 + (1 << (i - 1));
  }
  for (int i = 2; i <= 30; i++) {
    g[i][1] = (1 << (i - 1));
    for (int j = i - 1; j >= 1; j--) {
      int t = (i - j) % 2;
      g[i][1] += g[j][t ^ 1];
      g[i][0] += g[j][t];
    }
  }
  h[1] = g[1];
  for (int i = 2; i <= 30; i++) {
    h[i][1] = h[i - 1][1] + g[i][1];
    h[i][0] = h[i - 1][0] + g[i][0];
  }

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}