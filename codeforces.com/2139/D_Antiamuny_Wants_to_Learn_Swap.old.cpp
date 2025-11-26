#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::array<int, 2>>> ask(n + 1);
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    ask[r].push_back({l, i});
  }
  std::vector<int> ans(q + 1);
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) -> void {
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) -> int {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  std::vector<int> f;
  for (int i = 3; i <= n; i++) {
    if (a[i - 2] > a[i - 1] && a[i - 1] > a[i]) {
      f.push_back(i - 2);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    // cnt += i - 1 - query(a[i]);
    // add(a[i], i);
    for (auto [l, idx] : ask[i]) {
      auto p = std::ranges::lower_bound(f, l);
      if (p != f.end() && i - l + 1 >= 3 && *p + 2 <= i) {
        ans[idx] = 0;
      } else {
        ans[idx] = 1;
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << (ans[i] ? "YES" : "NO") << '\n';
  }
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