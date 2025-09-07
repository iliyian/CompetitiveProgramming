#include <bits/stdc++.h>
#define int long long
#include <iostream>
#define PII pair<int, int>
#define lson (p << 1)
#define rson (p << 1 | 1)
#define lowbit(x) x & -x
using namespace std;
using ll = long long;
inline int read() {
  int res = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      f = -1;
  for (; isdigit(c); c = getchar())
    res = (res << 1) + (res << 3) + (c & 15);
  return res * f;
}
template <typename T> inline void print(T x) {
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T> inline void Pr(T x, char c = '\n') {
  if (x < 0)
    putchar('-'), x = -x;
  print(x);
  putchar(c);
}
inline void write(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
  return;
}

const int p = 998244353;
/**/
const int N = 1e5 + 10;
int a[N];
int n, m, q;
int t[4 * N], lazy[4 * N];
int L[N], R[N];

void build2(int o, int l, int r, int x)
// 若当前节点大于x，将懒标记变为0
{
  if (l == r) {
    t[o] = (a[l] >= x);
    lazy[o] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build2(o << 1, l, mid, x);
  build2(o << 1 | 1, mid + 1, r, x);
  t[o] = t[o << 1] + t[o << 1 | 1];
  lazy[o] = 0;
}
void pushdown2(int o, int l, int r) {
  if (!lazy[o])
    return;
  lazy[o << 1] = lazy[o << 1 | 1] = lazy[o];
  int mid = (l + r) / 2;
  if (lazy[o] == 1) {
    t[o << 1] = mid - l + 1;
    t[o << 1 | 1] = r - mid;
  } else {
    t[o << 1] = t[o << 1 | 1] = 0;
  }
  lazy[o] = 0;
}
int query2(int o, int l, int r, int x, int y) {
  if (x <= l && y >= r)
    return t[o];
  if (x > r || y < l)
    return 0;
  int mid = (l + r) / 2;
  pushdown2(o, l, r);
  return query2(o << 1, l, mid, x, y) + query2(o << 1 | 1, mid + 1, r, x, y);
}
int querypo(int o, int l, int r, int x) {
  if (l == x && r == x)
    return t[o];
  pushdown2(o, l, r);
  int mid = (l + r) / 2;
  if (x <= mid)
    return (querypo(o << 1, l, mid, x));
  else
    return (querypo(o << 1 | 1, mid + 1, r, x));
}
void update2(int o, int l, int r, int x, int y, int val) {
  if (x <= l && y >= r) {
    t[o] = val * (r - l + 1);
    lazy[o] = val ? 1 : -1;
    return;
  }
  if (x > r || y < l)
    return;
  int mid = (l + r) / 2;
  pushdown2(o, l, r);
  update2(o << 1, l, mid, x, y, val);
  update2(o << 1 | 1, mid + 1, r, x, y, val);
  t[o] = t[o << 1] + t[o << 1 | 1];
}
const int maxn = 1e6 + 50;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int Mod = 1e9 + 7;
int op[N];
int k;
bool check(int x) {
  build2(1, 1, n, x);
  for (int i = 1; i <= m; i++) {
    int cnt1 = query2(1, 1, n, L[i], R[i]);

    if (op[i] == 0) {
      update2(1, 1, n, R[i] - cnt1 + 1, R[i], 1);
      update2(1, 1, n, L[i], R[i] - cnt1, 0);
    } else {
      update2(1, 1, n, L[i], L[i] + cnt1 - 1, 1);
      update2(1, 1, n, L[i] + cnt1, R[i], 0);
    }
  }
  return querypo(1, 1, n, k);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> op[i] >> L[i] >> R[i];
  }
  cin >> k;
  int lt = 1, rt = n, midt, an;
  while (lt <= rt) {
    midt = (lt + rt) >> 1;
    if (check(midt)) {
      an = midt;
      lt = midt + 1;
    } else {
      rt = midt - 1;
    }
  }
  cout << an << endl;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int _;
  // cin >> _;
  _ = 1;
  while (_--)
    solve();
  return 0;
}