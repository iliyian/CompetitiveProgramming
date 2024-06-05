// date: 2024-06-03 22:00:32
// tag: 线段树维护区间与单点操作

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

struct Seg {
  int cnt, val, tag;
} seg[N << 3];

Seg merge(const Seg &x, const Seg &y) {
  return {x.cnt + y.cnt, x.val + y.val, 0};
}

void addTag(int p, int c) {
  seg[p].val += c * seg[p].cnt;
  seg[p].tag += c;
}

void pushdown(int p) {
  if (seg[p].tag) {
    addTag(lc, seg[p].tag), addTag(rc, seg[p].tag);
    seg[p].tag = 0;
  }
}

void pushup(int p) {
  seg[p] = merge(seg[lc], seg[rc]);
}

void addPoint(int x, int s, int t, int p, int c) {
  if (x > t || x < s) return;
  if (x == s && x == t) {
    seg[p].cnt += c;
    return;
  };
  int mid = (s + t) / 2;
  pushdown(p);
  if (x <= mid) addPoint(x, s, mid, lc, c);
  else addPoint(x, mid + 1, t, rc, c);
  pushup(p);
}

void addRange(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    addTag(p, c);
    return;
  }
  int mid = (s + t) / 2;
  pushdown(p);
  if (l <= mid) addRange(l, r, s, mid, lc, c);
  if (r > mid) addRange(l, r, mid + 1, t, rc, c);
  pushup(p);
}

Seg query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return {};
  if (l <= s && t <= r) return seg[p];
  int mid = (s + t) / 2;
  pushdown(p);
  return merge(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int q, d;
  cin >> q >> d;
  unordered_set<int> vis;
  int ans = 0;
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    if (!vis.count(x)) {
      vis.insert(x);
      int cnt = query(x + 1, x + d, 1, N, 1).cnt;
      ans += cnt * (cnt - 1) / 2;
      ans += query(x - d, x - 1, 1, N, 1).val;
      addRange(x - d, x - 1, 1, N, 1, 1);

      addPoint(x, 1, N, 1, 1);
      addRange(x, x, 1, N, 1, cnt); // 基于前一行
    } else {
      vis.erase(x);
      int val = query(x, x, 1, N, 1).val;
      auto [c, v, t] = query(x - d, x - 1, 1, N, 1);
      ans -= val * (val - 1) / 2 + v - c;
      addRange(x - d, x - 1, 1, N, 1, -1);

      addRange(x, x, 1, N, 1, -val); // 基于后一行的cnt值改动
      addPoint(x, 1, N, 1, -1);
    }
    cout << ans << '\n';
  }

  return 0;
}