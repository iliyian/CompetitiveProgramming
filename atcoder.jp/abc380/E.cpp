#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
using namespace std;

constexpr int N = 5e5;

int n, q, d[N << 2], laz[N << 2], cnt[N + 1];

int merge(int x, int y) {
  if (!x) return y;
  if (!y) return x;
  if (x == y) return x;
  return -1;
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = s;
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  d[p] = merge(d[lc], d[rc]);
}

void P(int p, int c) {
  d[p] = c;
  laz[p] = c;
}

void pushdown(int p) {
  if (laz[p]) {
    P(lc, laz[p]);
    P(rc, laz[p]);
    laz[p] = 0;
  }
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return d[p];
  pushdown(p);
  return merge(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

void modify(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    P(p, c);
    return;
  }
  pushdown(p);
  modify(l, r, s, mid, lc, c);
  modify(l, r, mid + 1, t, rc, c);
  d[p] = merge(d[lc], d[rc]);
}

void solve() {
  memset(laz, 0, sizeof(laz));
  int n, q;
  std::cin >> n >> q;
  build(1, n, 1);
  std::fill(cnt + 1, cnt + n + 1, 1);
  while (q--) {
    int op, x, c;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> c;
      int l = 1, r = x, L = x, R = x;
      while (l <= r) {
        int mi = (l + r) / 2;
        if (query(mi, x, 1, n, 1) != -1) r = mi - 1, L = mi;
        else l = mi + 1;
      }
      l = x, r = n;
      while (l <= r) {
        int mi = (l + r) / 2;
        if (query(x, mi, 1, n, 1) != -1) l = mi + 1, R = mi;
        else r = mi - 1;
      }
      int prvcol = query(x, x, 1, n, 1);
      int len = R - L + 1;
      modify(L, R, 1, n, 1, c);
      // std::cout << L << ' ' << R << '\n';
      cnt[prvcol] -= len;
      cnt[c] += len;
    } else {
      std::cin >> c;
      std::cout << cnt[c] << '\n';
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
};