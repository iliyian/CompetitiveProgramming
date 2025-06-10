#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int N = n * 35;
  std::vector<std::array<int, 2>> tr(N + 1);
  // std::vector<int> L(N + 1), R(N + 1, 0);
  std::vector<std::vector<int>> vec(N + 1);
  int tot = 1;
  auto add = [&](int x, int pos) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!tr[u][idx]) tr[u][idx] = ++tot;
      u = tr[u][idx];
      vec[u].push_back(pos);
    }
  };
  for (int i = 1; i <= tot; i++) {
    std::sort(vec[i].begin(), vec[i].end());
  }
  for (int i = 1; i <= n; i++) {
    add(a[i], i);
  }
  while (q--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    int ans = 0, u = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      auto &v = vec[tr[u][idx ^ 1]];
      auto p = std::lower_bound(v.begin(), v.end(), l);
      if (p != v.end() && *p <= r) {
        u = tr[u][idx ^ 1];
        ans += 1ll << i;
      } else {
        u = tr[u][idx];
      }
    }
    std::cout << ans << '\n';
  }
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