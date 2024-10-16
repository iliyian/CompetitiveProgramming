#include <bits/stdc++.h>
#define int long long

std::vector<int> f(32);
std::vector<std::array<int, 2>> g(32), h(32), hh(32);

void solve() {
  int n;
  std::cin >> n;
  int k = 63 - __builtin_clzll(n);
  int ans = h[k][1] + (n - (1ll << k) + 1);
  int cur = 1 << k;
  for (int i = k; i >= 0; i--) {
    int t = k - i + 1;
    if (t == 1) continue;
    if (n >> i & 1) {
      cur += 1ll << i;
      if (t % 2 == 1) {
        ans += hh[i][0] + (n - cur + 1);
      } else {
        ans += hh[i][1];
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
    f[i] = f[i - 1] * 2 + (1ll << (i - 1));
  }
  for (int i = 2; i <= 30; i++) {
    g[i][1] = (1ll << (i - 1));
    for (int j = i - 1; j >= 1; j--) {
      int t = (i - j) % 2;
      g[i][1] += g[j][t ^ 1];
      g[i][0] += g[j][t];
    }
  }
  h[1] = hh[1] = g[1];
  for (int i = 2; i <= 30; i++) {
    h[i][1] = h[i - 1][1] + g[i][1];
    h[i][0] = h[i - 1][0] + g[i][0];

    hh[i][1] = hh[i - 1][1] + g[i][i & 1];
    hh[i][0] = hh[i - 1][0] + g[i][i & 1 ^ 1];
  }

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}