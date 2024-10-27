// date: 2024-10-25 10:26:29
// tag: 主席树维护小于某个值的和，在线

#include <bits/stdc++.h>
#define mid (s + t) / 2
#define int long long

constexpr int N = 2e7;

struct Seg {
  int lc, rc, sum;
};

std::vector<int> rt(N);
std::vector<Seg> seg(N);

int cnt = 0;

int update(int s, int t, int pre, int x) {
  int p = ++cnt;
  seg[p] = seg[pre];
  if (s == t) {
    seg[p].sum += x;
    return p;
  }
  if (x <= mid) seg[p].lc = update(s, mid, seg[p].lc, x);
  else seg[p].rc = update(mid + 1, t, seg[p].rc, x);
  seg[p].sum = seg[seg[p].lc].sum + seg[seg[p].rc].sum;
  return p;
}

int query(int s, int t, int l, int r, int x) {
  if (s > x) return 0;
  if (t <= x) return seg[r].sum - seg[l].sum;
  return query(s, mid, seg[l].lc, seg[r].lc, x) + query(mid + 1, t, seg[l].rc, seg[r].rc, x);
}

signed main() {
  freopen("G.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  rt[0] = update(0, 1e9, 0, 0);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    rt[i] = update(0, 1e9, rt[i - 1], a[i]);
  }
  int q, ans = 0;
  std::cin >> q;
  while (q--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    l ^= ans, r ^= ans, x ^= ans;
    ans = query(0, 1e9, rt[l - 1], rt[r], x);
    std::cout << ans << '\n';
  }
}