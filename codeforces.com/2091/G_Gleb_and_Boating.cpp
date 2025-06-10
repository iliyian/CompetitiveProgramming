#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::map<std::array<int, 4>, int> mp;
  auto dfs = [&](auto self, int pos, int dir, int ck, bool f) -> int {
    if (!ck) return ck;
    if (pos == n) return ck;
    if (ck < k - 10) return 0;
    if (mp.count({pos, dir, ck, f})) return mp[{pos, dir, ck, f}];
    int ans = 0;
    if (!f) {
      ans = self(self, pos, -dir, ck - 1, true);
    }
    for (int i = 1; i <= n; i++) {
      if (pos + dir * ck < 0 || pos + dir * ck > n) break;
      ans = std::max(ans, self(self, pos + dir * ck, dir, ck, false));
    }
    return mp[{pos, dir, ck, f}] = ans;
  };
  std::cout << dfs(dfs, 0, 1, k, 0) << '\n';
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