#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long v, nxt;
} e[600000];
long long t, n, a[300000], s[300000], h[300000], del[300000],
    he = 0, cnt = 0, ans = 1e10, tol = 0;
long long pre[300000], x[300000], sum[300000], g[300000];
void init() {
  for (int i = 1; i <= n; i++)
    del[i] = 0, h[i] = 0;
  tol = 0, cnt = 0;
}

void add_edge(long long u, long long v) {
  e[++cnt].nxt = h[u];
  e[cnt].v = v;
  h[u] = cnt;
}

long long dfs1(long long now, long long fa, long long cnt) {
  long long maxn = 0;
  s[now] = 1;
  if (del[now])
    return 0;
  for (long long i = h[now]; i; i = e[i].nxt)
    if (e[i].v != fa) {
      long long z = dfs1(e[i].v, now, cnt);
      s[now] += z, maxn = max(maxn, z);
    }
  if (max(maxn, cnt - s[now]) < ans)
    ans = min(ans, max(maxn, cnt - s[now])), he = now;
  return s[now];
}

void dfs2(long long now, long long fa) {
  if (del[now])
    return;
  s[now] = 1, pre[now] = x[a[now]], x[a[now]] = now;
  if (pre[now] == 0) {
    if (a[now] == a[he])
      tol++;
    else {
      tol += sum[a[now]];
      g[a[now]]++;
    }
  }
  for (long long i = h[now]; i; i = e[i].nxt)
    if (e[i].v != fa) {
      dfs2(e[i].v, now);
      if (del[e[i].v] == 0)
        s[now] += s[e[i].v];
    }
  x[a[now]] = pre[now];
}

void update(long long now, long long fa) {
  if (del[now])
    return;
  sum[a[now]] += g[a[now]], g[a[now]] = 0;
  for (long long i = h[now]; i; i = e[i].nxt)
    if (e[i].v != fa)
      update(e[i].v, now);
}

void clear(long long now, long long fa) {
  if (del[now])
    return;
  pre[now] = 0, x[a[now]] = 0, sum[a[now]] = 0;
  for (long long i = h[now]; i; i = e[i].nxt)
    if (e[i].v != fa)
      clear(e[i].v, now);
}

void dfz(long long now, long long siz) {
  if (del[now])
    return;
  ans = 1e10;
  dfs1(now, 0, siz);
  for (long long i = h[he]; i; i = e[i].nxt) {
    dfs2(e[i].v, he);
    update(e[i].v, he);
  }
  for (long long i = h[he]; i; i = e[i].nxt)
    clear(e[i].v, he);
  del[he] = 1;
  for (long long i = h[he]; i; i = e[i].nxt)
    dfz(e[i].v, s[e[i].v]);
}

int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    init();
    for (long long i = 1; i <= n; i++)
      scanf("%lld", &a[i]);
    for (long long i = 1; i <= n - 1; i++) {
      long long u = 0, v = 0;
      scanf("%lld%lld", &u, &v);
      add_edge(u, v), add_edge(v, u);
    }
    dfz(1, n);
    printf("%lld\n", tol);
  }
  return 0;
}