#include <bits/stdc++.h>
#define LL long long
#define maxn 1000010
using namespace std;
struct Edge {
  int to, next;
} edge[maxn << 1];
int num, head[maxn], a[maxn], f[maxn], vis[maxn], n;
LL dp[maxn][2], ans;

inline int read() {
  int s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      w = -1;
  for (; isdigit(c); c = getchar())
    s = (s << 1) + (s << 3) + (c ^ 48);
  return s * w;
}

void addedge(int x, int y) { edge[++num] = (Edge){y, head[x]}, head[x] = num; }

void dfs(int u, int x) {
  vis[u] = 1;
  dp[u][0] = 0, dp[u][1] = a[u];
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v != x) {
      dfs(v, x);
      dp[u][0] += max(dp[v][0], dp[v][1]);
      dp[u][1] += dp[v][0];
    } else
      dp[v][1] = -1e9;
  }
}

void solve(int u) {
  while (!vis[u])
    vis[u] = 1, u = f[u];
  dfs(u, u);
  LL sum = max(dp[u][0], dp[u][1]);
  u = f[u];
  dfs(u, u);
  ans += max(sum, max(dp[u][0], dp[u][1]));
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read(), f[i] = read();
    addedge(f[i], i);
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i])
      solve(i);
  printf("%lld\n", ans);
  return 0;
}