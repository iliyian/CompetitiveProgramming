#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 2e5;
constexpr int D = N * 2 + 1e8 + 1;

struct Seg {
  int ld, rd, cnt, len;
};
std::vector<Seg> seg(N << 2);

Seg merge(const Seg &x, const Seg &y) {
  return Seg{
    x.ld + y.ld + y.cnt * x.len,
    x.rd + y.rd + x.cnt * y.len,
    x.cnt + y.cnt,
    x.len + y.len,
  };
}

void pull(int p) {
  seg[p] = merge(seg[lc], seg[rc]);
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    int len = t - s + 1;
    seg[p] = {len * (len - 1) / 2 * c, len * (len - 1) / 2 * c, len * c, len};
    return;
  }
  add(l, r, s, mid, lc, c);
  add(l, r, mid + 1, t, rc, c);
  pull(p);
}

int query(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) {
    if (c >= r) return seg[p].rd + (c - r) * seg[p].cnt;
    if (c <= l) return seg[p].ld + (l - c) * seg[p].cnt;
    assert(false);
  }
  return query(l, r, s, mid, lc, c) + query(l, r, mid + 1, t, rc, c);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("A.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    add(a[i], a[i], 1, n, 1, 1);
  }
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int t, g;
    std::cin >> t >> g;
    int cur = a[t];
    std::cout << query()
    a[t] = g;
  }
}