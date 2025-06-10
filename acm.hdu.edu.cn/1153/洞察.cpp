#include <bits/stdc++.h>
#define int long long

void solve() {
  int k, b, c, v;
  std::cin >> k >> b >> c >> v;
  // std::vector<int> vec;
  auto calc = [&](int l, int r) -> int {
    int ll = std::max(-1.0l, std::floor((long double)(l - b - 1) / k)),
        rr = std::max(-1.0l, std::floor((long double)(r - b) / k));
    // int ll = (l - 1 + k - b % k) / k;
    // int rr = (r + k - b % k) / k;
    return rr - ll;
  };
  auto dfs = [&](auto self, int u, int c, int v, int l, int r) -> int {
    if (u == -1) {
      assert(l == r);
      if (l >= b && (l - b) % k == 0) {
        // std::cerr << l << '\n';
        // vec.push_back(l);
        return 1;
      }
      return 0;
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
      int ans = calc(l ^ (1ll << u), r);
      return ans + self(self, u - 1, c, v, l, r ^ (1ll << u));
    }
    if (ci == 0 && vi == 1) {
      int ans = calc(l, r ^ (1ll << u));
      return ans + self(self, u - 1, c, v, l ^ (1ll << u), r);
    }
    assert(false);
  };
  std::cout << dfs(dfs, 61, c, v, 0, (1ll << 62) - 1) << '\n';
  // std::sort(vec.begin(), vec.end());
  // for (auto i : vec) {
  //   std::cerr << i << '\n';
  // }
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