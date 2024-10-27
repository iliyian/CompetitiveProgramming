// date: 2024-10-20 21:48:33
// tag: 线段树二分，离线，区间mex

#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
#define int long long

constexpr int N = 2e5;
std::vector<int> d((N + 5) << 2);

void add(int x, int s, int t, int p, int pos) {
  if (s == t) {
    d[p] = pos;
    return;
  }
  if (x > mid) add(x, mid + 1, t, rc, pos);
  else add(x, s, mid, lc, pos);
  d[p] = std::min(d[lc], d[rc]);
}

int query(int s, int t, int p, int l) {
  if (s == t) return s;
  if (d[lc] < l) return query(s, mid, lc, l);
  return query(mid + 1, t, rc, l);
}

signed main() {
  freopen("main.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    ask[r].push_back({l, i});
  }
  for (int i = 1; i <= n; i++) {
    std::sort(ask[i].begin(), ask[i].end());
  }
  std::vector<int> ans(q + 1);
  for (int r = 1; r <= n; r++) {
    add(a[r], 0, N, 1, r);
    for (auto &[l, id] : ask[r]) {
      ans[id] = query(0, N, 1, l);
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
  }
  std::cout << '\n';
  return 0;
}