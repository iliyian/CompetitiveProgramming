// date: 2025-01-24 23:50:54
// tag: 区间包含的特殊判定

#include <bits/stdc++.h>
#define int long long

struct Node {
  int l, r, id;
  bool operator < (const Node &b) const {
    return std::tie(l, r) < std::tie(b.l, b.r);
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Node> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i].l >> a[i].r;
    a[i].id = i;
  }
  if (m == 1) {
    if (a[1].l == 1 && a[1].r == n) {
      std::cout << 1 << '\n' << 1 << '\n';
    } else {
      std::cout << -1 << '\n';
    }
    return;
  }
  std::vector<int> ans(m + 1);
  auto answer = [&](int x) {
    std::cout << x << '\n';
    for (int i = 1; i <= m; i++) {
      std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
  };
  for (int i = 1; i <= m; i++) {
    if (a[i].l == 1 && a[i].r == n) {
      ans[i] = 1;
      answer(1);
      return;
    }
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= m; i++) {
    auto p = std::upper_bound(a.begin() + 1, a.end(), Node{a[i].r, INT_MAX, 0}) - a.begin();
    if (p != m + 1) { // 完全不交
      ans[a[i].id] = 2;
      ans[a[p].id] = 2;
      answer(2);
      return;
    }
    if (i < m && (a[i].l == a[i + 1].l || a[i + 1].r <= a[i].r)) { // 完全覆盖
      if (a[i].l == a[i + 1].l) {
        std::swap(a[i], a[i + 1]);
      }
      ans[a[i].id] = 1;
      ans[a[i + 1].id] = 2;
      answer(2);
      return;
    }
  }
  if (a[1].l == 1 && a[m].r == n) {
    ans[a[1].id] = ans[a[m].id] = 1;
    answer(2);
    return;
  }
  if (m == 2) {
    std::cout << -1 << '\n';
    return;
  }
  ans[a[1].id] = ans[a[m].id] = 2;
  ans[a[2].id] = 1;
  answer(3);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}