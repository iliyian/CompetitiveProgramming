// LUOGU_RID: 140201301
#include <bits/stdc++.h>

int n, m, a[55][55], A[55], B[55];

int preans;

const int M = 10005, inf = 1000, N = 105;

int nxt[M], ver[M], head[105], S, T, f[M], c[M], dis[N], vis[N], p1[N], p2[N],
    tot = 1;

inline void add_edge(int x, int y, int vo, int w) {
  ++tot;
  nxt[tot] = head[x];
  head[x] = tot;
  ver[tot] = y;
  f[tot] = vo;
  c[tot] = w;
  ++tot;
  nxt[tot] = head[y];
  head[y] = tot;
  ver[tot] = x;
  f[tot] = 0;
  c[tot] = -w;
  return;
}

int cal() {
  int res = 0, now = T;
  while (now != S) {
    res += c[p2[now]];
    f[p2[now]] -= 1;
    f[p2[now] ^ 1] += 1;
    now = p1[now];
  }
  return res;
}

/*int spfa(){
  for(int i = 1; i <= T; ++i) dis[i] = inf;
  memset(vis, 0, sizeof vis);
  dis[S] = 0; std::queue <int> q; vis[S] = 1; q.push(S);
  while(q.size()){
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = nxt[i]){
      if(f[i] == 0) continue;
      if(dis[ver[i]] > dis[u] + c[i]){
        dis[ver[i]] = dis[u] + c[i];
        p1[ver[i]] = u;
        p2[ver[i]] = i;
        if(!vis[ver[i]]) q.push(ver[i]);
      }
    }
  }
  return dis[T] < inf;
}*/

struct node {
  int x, d;
};

struct cmp {
  inline bool operator()(node a, node b) { return a.d > b.d; }
};

std::priority_queue<node, std::vector<node>, cmp> q;

int dijkstra() {
  for (int i = 1; i <= T; ++i)
    dis[i] = inf;
  dis[S] = 0;
  while (q.size())
    q.pop();
  q.push((node){S, 0});
  while (q.size()) {
    auto u = q.top();
    q.pop();
    if (u.d != dis[u.x])
      continue;
    if (u.x == T)
      return 1;
    for (int i = head[u.x]; i; i = nxt[i]) {
      if (f[i] == 0)
        continue;
      if (dis[ver[i]] > dis[u.x] + c[i]) {
        dis[ver[i]] = dis[u.x] + c[i];
        p1[ver[i]] = u.x;
        p2[ver[i]] = i;
        q.push((node){ver[i], dis[ver[i]]});
      }
    }
  }
  return 0;
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);
  int s = 0;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]), s += A[i];
  for (int j = 1; j <= m; ++j)
    scanf("%d", &B[j]), s -= B[j];
  if (s != 0) {
    printf("-1\n");
    return;
  }
  for (int i = 1; i <= n; ++i)
    s += A[i];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      preans += a[i][j];
  preans -= s;
  S = n + m + 1, T = S + 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] == 0)
        add_edge(i, j + n, 1, 2);
      else
        add_edge(i, j + n, 1, 0);
  for (int i = 1; i <= n; ++i)
    add_edge(S, i, A[i], 0);
  for (int i = 1; i <= m; ++i)
    add_edge(i + n, T, B[i], 0);
  int mf = 0, mc = 0;
  while (dijkstra()) {
    mf += 1, mc += cal();
    if (mf == s)
      break;
  }
  if (mf < s) {
    printf("-1\n");
    return;
  }
  printf("%d\n", preans + mc);
  return;
}

int main() {
  freopen("E.in", "r", stdin);
  int T = 1;
  while (T--)
    solve();
  return 0;
}