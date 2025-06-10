#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int n, m, Q, a[N], b[N], root;
int d[N], T = 24, f[N][25];
int dfn[N], cnt, low[N];
int tot, ver[N << 1], Next[N << 1], head[N];
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x) {
  dfn[x] = ++cnt;
  for (int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (d[y])
      continue;
    d[y] = d[x] + 1;
    f[y][0] = x;
    for (int j = 1; j <= T; j++)
      f[y][j] = f[f[y][j - 1]][j - 1];
    dfs(y);
  }
  low[x] = cnt;
}
int find(int x, int R) {
  for (int i = T; i >= 0; i--)
    if (a[f[x][i]] <= R)
      x = f[x][i];
  return x;
}
struct tree {
  int lc, rc, sum;
} t[N * 20];
int num, Root[N];
int build(int l, int r) {
  int p = ++num;
  t[p].sum = 0;
  if (l == r)
    return p;
  int mid = (l + r) / 2;
  t[p].lc = build(l, mid);
  t[p].rc = build(mid + 1, r);
  return p;
}
int insert(int now, int l, int r, int x, int val) {
  int p = ++num;
  t[p] = t[now];
  if (l == r) {
    t[p].sum += val;
    return p;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    t[p].lc = insert(t[now].lc, l, mid, x, val);
  else
    t[p].rc = insert(t[now].rc, mid + 1, r, x, val);
  t[p].sum = t[t[p].lc].sum + t[t[p].rc].sum;
  return p;
}
int ask(int p, int q, int l, int r, int k) {
  int mid = (l + r) / 2;
  int ans = 0;
  if (l == r)
    return t[q].sum - t[p].sum;
  if (k <= mid)
    ans += ask(t[p].lc, t[q].lc, l, mid, k);
  else {
    ans += t[t[q].lc].sum - t[t[p].lc].sum;
    ans += ask(t[p].rc, t[q].rc, mid + 1, r, k);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    add(x, y);
    add(y, x);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    if (a[root] < a[i])
      root = i;
  }
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;

  d[root] = 1, dfs(root);

  Root[0] = build(1, m);
  for (int i = 1, x; i <= n; i++) {
    x = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    Root[i] = insert(Root[i - 1], 1, cnt, x, 1);
  }
  a[0] = INT_MAX;
  cin >> Q;
  while (Q--) {
    int x, L, R;
    cin >> x >> L >> R;
    if (a[x] < L || a[x] > R) {
      cout << 0 << endl;
      continue;
    }
    x = find(x, R);
    //		cout<<x<<endl;
    int tmp = upper_bound(b + 1, b + m + 1, L) - b - 1;
    cout << low[x] - dfn[x] + 1 -
                ask(Root[dfn[x] - 1], Root[low[x]], 1, m, tmp - 1)
         << endl;
  }
  return 0;
}