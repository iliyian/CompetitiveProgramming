#include <bits/stdc++.h>
#define ll long long
#define N 900005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;
struct Tree {
  int l, r, sum, num;
} t[N << 2];
int n, m, root = 1, a[N];
int tot, ver[N << 1], Next[N << 1], head[N];
int son[N], siz[N], dep[N], top[N], fa[N], cnt, dfn[N], id[N];
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void update(int p) {
  t[p].sum = t[lc].sum + t[rc].sum;
  t[p].num = t[lc].num + t[rc].num;
}
void change(int p, int x, int s) {
  if (t[p].l == t[p].r) {
    t[p].sum = s;
    if (s == 1)
      t[p].num = 1;
    return;
  }
  int mid = (t[p].l + t[p].r) >> 1;
  if (x <= mid)
    change(lc, x, s);
  else
    change(rc, x, s);
  update(p);
}
int query(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r)
    return t[p].sum;
  int mid = (t[p].l + t[p].r) / 2;
  int val = 0;
  if (l <= mid)
    val += query(lc, l, r);
  if (r > mid)
    val += query(rc, l, r);
  return val;
}
int query1(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r)
    return t[p].num;
  int mid = (t[p].l + t[p].r) / 2;
  int val = 0;
  if (l <= mid)
    val += query1(lc, l, r);
  if (r > mid)
    val += query1(rc, l, r);
  return val;
}
void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].sum = a[id[l]];
    if (a[id[l]] == 1)
      t[p].num = 1;
    return;
  }
  int mid = (l + r) / 2;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  update(p);
}
void dfs1(int x) {
  son[x] = -1;
  siz[x] = 1;
  for (int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (!dep[y]) {
      dep[y] = dep[x] + 1;
      fa[y] = x;
      dfs1(y);
      siz[x] += siz[y];
      if (son[x] == -1 || siz[y] > siz[son[x]])
        son[x] = y;
    }
  }
}
void dfs2(int x, int t) {
  top[x] = t;
  cnt++;
  dfn[x] = cnt;
  id[cnt] = x;
  if (son[x] == -1)
    return;
  dfs2(son[x], t);
  for (int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (y != son[x] && y != fa[x])
      dfs2(y, y);
  }
}

int ask(int x, int y) {
  int val = 0, count = 0, len = 0, X = x, Y = y;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]])
      swap(x, y);
    val += query(1, dfn[top[x]], dfn[x]);
    count += query1(1, dfn[top[x]], dfn[x]);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y])
    swap(x, y);
  val += query(1, dfn[x], dfn[y]);
  count += query1(1, dfn[x], dfn[y]);
  len = dep[X] + dep[Y] - 2 * dep[x] + 1;
  if (len > 24) {
    if (val - count <= 24)
      return 1;
    return 0;
  } else {
    int p[30], lenp = 0, dp[30][2] = {};
    p[++lenp] = X;
    while (X != x) {
      X = fa[X];
      p[++lenp] = X;
    }
    lenp = len;
    while (Y != x) {
      p[lenp--] = Y;
      Y = fa[Y];
    }
    //		for (int i=1;i<=len;i++)cout<<p[i]<<' ';
    //		cout<<endl;
    //		for (int i=1;i<=len;i++)cout<<a[p[i]]<<' ';
    //		cout<<endl;
    dp[a[p[1]]][1] = 1;
    for (int i = 2; i <= len; i++) {
      for (int j = 1; j <= 24; j++)
        dp[j][i & 1] = 0;
      for (int j = 1; j <= 24; j++)
        if (dp[j][(i - 1) & 1]) {
          int k = j + a[p[i]];
          if (k <= 24)
            dp[k][i & 1] = 1;
          k = j * a[p[i]];
          if (k <= 24)
            dp[k][i & 1] = 1;
        }
    }
    if (dp[24][len & 1])
      return 1;
    else
      return 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    add(x, y), add(y, x);
  }
  dep[root] = 1, dfs1(root);
  dfs2(root, root);
  build(1, 1, n);
  while (m--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1)
      cout << ask(x, y) << endl;
    else
      a[x] = y, change(1, dfn[x], y);
  }
  return 0;
}