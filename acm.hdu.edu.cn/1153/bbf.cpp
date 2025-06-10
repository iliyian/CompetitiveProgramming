#include <bits/stdc++.h>
#define int long long

void solve() {
  int k, b, c, v;
  std::cin >> k >> b >> c >> v;

  int ans = 0;
  for (int i = 0; i <= 10000000; i++) {
    if (((k * i + b) ^ c) <= v) {
      ans++;
      // std::cout << i << '\n';
    }
  }
  std::cout << ans << '\n';
  return;

  auto calc = [&](int l, int r) {
    int ll = (l + k - 1 - b) / k;
    int rr = (r - b) / k;
    if (ll < 0 || rr < 0) return 0ll;
    return std::max(0ll, rr - ll + 1);
  };
  auto dfs = [&](auto self, int u, int c, int v, int l, int r) -> int {
    if (u == -1) {
      assert(l == r);
      return l >= b && (l - b) % k == 0;
    }
    int ci = c >> u & 1, vi = v >> u & 1;
    if (ci == 0 && vi == 0) {
      r ^= 1ll << u;
      return self(self, u - 1, c, v, l, r);
    }
    if (ci == 1 && vi == 0) {
      l ^= 1ll << u;
      return self(self, u - 1, c, v, l, r);
    }
    if (ci == 1 && vi == 1) {
      return self(self, u - 1, c, v, l ^ (1ll << u), r) + self(self, u - 1, c, v, l, r ^ (1ll << u));
    }
    if (ci == 0 && vi == 1) {
      int ans = calc(l, r ^ (1ll << u));
      return ans + self(self, u - 1, c, v, l ^ (1ll << u), r);
    }
    assert(false);
  };
  std::cout << dfs(dfs, 59, c, v, 0, (1ll << 60) - 1) << '\n';
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