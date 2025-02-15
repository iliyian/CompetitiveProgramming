// date: 2025-02-09 17:32:00
// tag: 疑似可持久化线段树模板

#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc seg[p].l
#define rc seg[p].r

constexpr int N = 2e5;

struct Seg {
  int l, r, sum;
};

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    auto &[l, r, x] = a[i];
    std::cin >> l >> r >> x;
  }
  std::vector<std::pair<int, int>> vec(m + 1);
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    vec[i] = {x, i};
  }
  int tot = 0;
  std::vector<Seg> seg(N << 5);
  auto update = [&](auto self, int s, int t, int x, int pre) -> int {
    int p = ++tot;
    seg[p] = seg[pre];
    seg[p].sum++;
    if (s == t) return p;
    if (x <= mid) lc = self(self, s, mid, x, lc);
    else rc = self(self, mid + 1, t, x, rc);
    return p;
  };
  auto query = [&](auto self, int s, int t, int p1, int p2, int k) -> int {
    if (s == t) return s;
    int sum = seg[seg[p2].l].sum - seg[seg[p1].l].sum;
    if (sum >= k) return self(self, s, mid, seg[p1].l, seg[p2].l, k);
    return self(self, mid + 1, t, seg[p1].r, seg[p2].r, k - sum);
  };
  std::sort(vec.begin() + 1, vec.end());
  std::vector<int> rt(m + 1);
  for (int i = 1; i <= m; i++) {
    rt[i] = update(update, 1, m, vec[i].second, rt[i - 1]);
  }
  std::vector<int> ans(m + 1);
  for (int i = 1; i <= n; i++) {
    auto l = std::lower_bound(vec.begin() + 1, vec.end(), std::pair{a[i][0], 0ll}) - vec.begin();
    auto r = std::upper_bound(vec.begin() + 1, vec.end(), std::pair{a[i][1], LLONG_MAX}) - vec.begin() - 1;
    // std::cerr << l << ' ' << r << '\n';
    if (r - l + 1 < a[i][2]) continue;
    ans[query(query, 1, m, rt[l - 1], rt[r], a[i][2])]++;
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}