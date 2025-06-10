#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  std::map<int, std::vector<int>> pos;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]].push_back(i);
  }
  // std::vector<std::array<int, 4>> ask(q + 1);
  // for (int i = 1; i <= q; i++) {
  //   auto &[l, r, k, id] = ask[i];
  //   std::cin >> k >> l >> r;
  //   id = i;
  // }
  // std::sort(ask.begin() + 1, ask.end());
  // std::vector<int> ans(n + 1);
  // int cur = 0;
  for (int i = 1; i <= q; i++) {
    // auto [l, r, k, id] = ask[i];
    int k, l, r;
    std::cin >> k >> l >> r;
    std::vector<std::array<int, 2>> pos2;
    auto add = [&](int j) {
      int t = k;
      // while (t % j == 0) cnt++, t /= j;
      if (!pos.count(j)) return;
      auto &v = pos[j];
      auto p = std::lower_bound(v.begin(), v.end(), l);
      if (p == v.end() || *p > r) return;
      pos2.push_back({*p, j});
    };
    for (int j = 2; j * j <= k; j++) {
      if (k % j == 0) {
        add(j);
        if (j * j != k) {
          add(k / j);
        }
      }
    }
    add(k);
    int res = 0;
    if (pos2.empty()) {
      res = (r - l + 1) * k;
    }
    std::sort(pos2.begin(), pos2.end());
    for (int j = 0; j < pos2.size(); j++) {
      auto [p, d] = pos2[j];
      int nxtp = (j == pos2.size() - 1 ? r + 1 : pos2[j + 1][0]);
      if (j == 0) {
        res += k * (p - l);
      }
      while (k % d == 0) k /= d;
      res += (nxtp - p) * k;
    }
    // ans[id] = res;
    std::cout << res << '\n';
  }
  // for (int i = 1; i <= q; i++) {
  //   std::cout << ans[i] << ' ';
  // }
  // std::cout << '\n';
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