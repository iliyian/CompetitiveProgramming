#include <cctype>
#include <cstdio>

#define lc o << 1
#define rc o << 1 | 1
#define mid (l + r) / 2
using namespace std;

const int N = 100010;
int n, m, p;
int T[4 * N], lazy[4 * N];   // segment tree
int a[N], ch[N], L[N], R[N]; // the information by reading

inline int read() {
  char ch = getchar();
  int x = 0;
  while (!isdigit(ch))
    ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

inline void build(int o, int l, int r, int x) {
  if (l == r) {
    T[o] = a[l] >= x;
    lazy[o] = 0;
    return;
  }
  build(lc, l, mid, x);
  build(rc, mid + 1, r, x);
  T[o] = T[lc] + T[rc];
  lazy[o] = 0;
}

inline void pushdown(int o, int l, int r) {
  if (!lazy[o])
    return;
  lazy[lc] = lazy[rc] = lazy[o];
  if (lazy[o] == 1) {
    T[lc] = mid - l + 1;
    T[rc] = r - mid;
  } else
    T[lc] = T[rc] = 0;
  lazy[o] = 0;
}

inline int query(int o, int l, int r, int x, int y) {
  if (x <= l && y >= r)
    return T[o];
  if (x > r || y < l)
    return 0;
  pushdown(o, l, r);
  return query(lc, l, mid, x, y) + query(rc, mid + 1, r, x, y);
}

inline int queryPoint(int o, int l, int r, int x) {
  if (l == x && r == x)
    return T[o];
  pushdown(o, l, r);
  if (x <= mid)
    return queryPoint(lc, l, mid, x);
  else
    return queryPoint(rc, mid + 1, r, x);
}

inline void update(int o, int l, int r, int x, int y, int val) {
  if (x <= l && y >= r) {
    T[o] = val * (r - l + 1);
    lazy[o] = val ? 1 : -1;
    return;
  }
  if (x > r || y < l)
    return;
  pushdown(o, l, r);
  update(lc, l, mid, x, y, val);
  update(rc, mid + 1, r, x, y, val);
  T[o] = T[lc] + T[rc];
}

inline bool check(int x) {
  build(1, 1, n, x);
  for (int i = 1; i <= m; i++) {
    int cnt1 = query(1, 1, n, L[i], R[i]);
    if (ch[i] == 0) {
      update(1, 1, n, R[i] - cnt1 + 1, R[i], 1);
      update(1, 1, n, L[i], R[i] - cnt1, 0);
    } else {
      update(1, 1, n, L[i], L[i] + cnt1 - 1, 1);
      update(1, 1, n, L[i] + cnt1, R[i], 0);
    }
  }
  return queryPoint(1, 1, n, p);
}

int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i <= m; i++) {
    ch[i] = read();
    L[i] = read();
    R[i] = read();
  }
  p = read();
  int ll = 1, rr = n, midd, ans;
  while (ll <= rr) {
    midd = (ll + rr) >> 1;
    if (check(midd))
      ans = midd, ll = midd + 1;
    else
      rr = midd - 1;
  }
  printf("%d\n", ans);
  return 0;
}