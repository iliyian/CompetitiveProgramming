// date: 2024-10-16 22:15:31
// tag: 区间颜色数

#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("F.in", "r", stdin);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::array<int, 2>>> ask(n + 1);
  std::vector<int> ans(q + 1);
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    ask[r].push_back({l, i});
  }
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) -> void {
    if (!x) return;
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) -> int {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    add(pos[a[i]], -1);
    pos[a[i]] = i;
    add(i, 1);
    for (auto &[l, idx] : ask[i]) {
      ans[idx] = query(i) - query(l - 1);
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}