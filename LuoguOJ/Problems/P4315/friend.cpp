#include <iostream>
using namespace std;
const int N = 100005;
struct EDGE {
  int a, b, c;
} edge[N];
struct Edge {
  int e, to, nxt;
} g[N << 1];
int h[N], idx;
int big_son[N], siz[N], dep[N], father[N];
int a[N], n;
int vis_cnt, dfn[N], top[N];
int w[N << 2], tag_set[N << 2], tag_add[N << 2];
void add(int a, int b, int c) { g[++idx] = {c, b, h[a]}, h[a] = idx; }
void dfs1(int u, int fa) {
  father[u] = fa;
  siz[u] = 1;
  for (int i = h[u]; i; i = g[i].nxt) {
    int j = g[i].to;
    if (j == fa)
      continue;
    dep[j] = dep[u] + 1;
    dfs1(j, u);
    siz[u] += siz[j];
    if (siz[j] > siz[big_son[u]])
      big_son[u] = j;
  }
}
void dfs2(int u, int fa, int Top) {
  top[u] = Top;
  dfn[u] = ++vis_cnt;
  if (big_son[u])
    dfs2(big_son[u], u, Top);
  for (int i = h[u]; i; i = g[i].nxt) {
    int j = g[i].to;
    if (j == fa)
      continue;
    if (j == big_son[u]) {
      a[dfn[j]] = g[i].e;
      continue;
    }
    dfs2(j, u, j);
    a[dfn[j]] = g[i].e;
  }
}
inline void pushup(int u) { w[u] = max(w[u << 1], w[u << 1 | 1]); }
void build(int u, int l, int r) {
  tag_set[u] = -1;
  if (l == r) {
    w[u] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  pushup(u);
}
inline void maketag(int u, int x, int op) {
  if (op == 1) {
    tag_add[u] = 0;
    w[u] = tag_set[u] = x;
  } else {
    if (tag_set[u] == -1)
      tag_add[u] += x;
    else
      tag_set[u] += x;
    w[u] += x;
  }
}
inline void pushdown(int u) {
  if (tag_set[u] == -1) {
    maketag(u << 1, tag_add[u], 2);
    maketag(u << 1 | 1, tag_add[u], 2);
    tag_add[u] = 0;
  } else {
    maketag(u << 1, tag_set[u], 1);
    maketag(u << 1 | 1, tag_set[u], 1);
    tag_set[u] = -1;
  }
}
int query(int u, int l, int r, int L, int R) {
  if (L <= l && r <= R)
    return w[u];
  pushdown(u);
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid)
    ans = query(u << 1, l, mid, L, R);
  if (mid < R)
    ans = max(ans, query(u << 1 | 1, mid + 1, r, L, R));
  return ans;
}
void update(int u, int l, int r, int L, int R, int x, int op) {
  if (L <= l && r <= R) {
    maketag(u, x, op);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(u);
  if (L <= mid)
    update(u << 1, l, mid, L, R, x, op);
  if (mid < R)
    update(u << 1 | 1, mid + 1, r, L, R, x, op);
  pushup(u);
}
void update2(int x, int y, int z, int op) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]])
      swap(x, y);
    update(1, 1, n, dfn[top[x]], dfn[x], z, op);
    x = father[top[x]];
  }
  if (dfn[x] > dfn[y])
    swap(dfn[x], dfn[y]);
  if (x != y)
    update(1, 1, n, dfn[x] + 1, dfn[y], z, op);
}
int query2(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]])
      swap(x, y);
    ans = max(ans, query(1, 1, n, dfn[top[x]], dfn[x]));
    x = father[top[x]];
  }
  if (dfn[x] > dfn[y])
    swap(dfn[x], dfn[y]);
  if (x != y)
    ans = max(ans, query(1, 1, n, dfn[x] + 1, dfn[y]));
  return ans;
}
int main() {
  freopen("main.in", "r", stdin);
  freopen("friend.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c);
    add(b, a, c);
    edge[i] = {a, b, c};
  }
  dfs1(1, 1);
  dfs2(1, 1, 1);
  build(1, 1, n);
  char op[7];
  while (scanf("%s", op) && op[0] != 'S') {
    if (op[1] == 'h') {
      int k, w;
      scanf("%d%d", &k, &w);
      int a = edge[k].a, b = edge[k].b;
      if (dep[a] < dep[b])
        swap(a, b);
      update(1, 1, n, dfn[a], dfn[a], w, 2);
    } else if (op[0] == 'C') {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      update2(x, y, z, 1);
    } else if (op[0] == 'A') {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      update2(x, y, z, 2);
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      printf("%d\n", query2(x, y));
    }
  }
  return 0;
}