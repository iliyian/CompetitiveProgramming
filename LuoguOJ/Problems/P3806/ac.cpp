// niiick
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int read() {
  int f = 1, x = 0;
  char ss = getchar();
  while (ss < '0' || ss > '9') {
    if (ss == '-')
      f = -1;
    ss = getchar();
  }
  while (ss >= '0' && ss <= '9') {
    x = x * 10 + ss - '0';
    ss = getchar();
  }
  return f * x;
}

const int inf = 10000000;
const int maxn = 100010;
int n, m;
struct node {
  int v, dis, nxt;
} E[maxn << 1];
int tot, head[maxn];
int maxp[maxn], siz[maxn], dis[maxn], rem[maxn];
int vis[maxn], test[inf], judge[inf], q[maxn * 10];
int query[1010];
int sum, rt;
int ans;

void add(int u, int v, int dis) {
  E[++tot].nxt = head[u];
  E[tot].v = v;
  E[tot].dis = dis;
  head[u] = tot;
}

void getrt(int u, int pa) {
  siz[u] = 1;
  maxp[u] = 0;
  for (int i = head[u]; i; i = E[i].nxt) {
    int v = E[i].v;
    if (v == pa || vis[v])
      continue;
    getrt(v, u);
    siz[u] += siz[v];
    maxp[u] = max(maxp[u], siz[v]);
  }
  maxp[u] = max(maxp[u], sum - siz[u]);
  if (maxp[u] < maxp[rt])
    rt = u;
}

void getdis(int u, int fa) {
  if (dis[u] > 1e7) return;
  rem[++rem[0]] = dis[u];
  for (int i = head[u]; i; i = E[i].nxt) {
    int v = E[i].v;
    if (v == fa || vis[v])
      continue;
    dis[v] = dis[u] + E[i].dis;
    getdis(v, u);
  }
}

void calc(int u) {
  int p = 0;
  for (int i = head[u]; i; i = E[i].nxt) {
    int v = E[i].v;
    if (vis[v])
      continue;
    rem[0] = 0;
    dis[v] = E[i].dis;
    getdis(v, u); // 处理u的每个子树的dis

    for (int j = rem[0]; j; --j)   // 遍历当前子树的dis
      for (int k = 1; k <= m; ++k) // 遍历每个询问
        if (query[k] >= rem[j])
          test[k] |= judge[query[k] - rem[j]];
    // 如果query[k]-rem[j]d的路径存在就标记第k个询问

    for (int j = rem[0]; j; --j) // 保存出现过的dis于judge
      q[++p] = rem[j], judge[rem[j]] = 1;
  }
  for (int i = 1; i <= p; ++i) // 处理完这个子树就清空judge
    judge[q[i]] = 0;           // 特别注意一定不要用memeset，会T
}

int totc = 0;
void solve(int u) {
  // judge[i]表示到根距离为i的路径是否存在
  totc++;
  vis[u] = judge[0] = 1;
  calc(u);                               // 处理以u为根的子树
  for (int i = head[u]; i; i = E[i].nxt) // 对每个子树进行分治
  {
    int v = E[i].v;
    if (vis[v])
      continue;
    sum = siz[v];
    maxp[rt = 0] = inf; // 注意sum是以v为根的子树大小
    getrt(v, 0);
    solve(rt); // 在子树中找重心并递归处理
  }
}

int main() {
  n = read();
  m = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read(), dis = read();
    add(u, v, dis);
    add(v, u, dis);
  }
  for (int i = 1; i <= m; ++i)
    query[i] = read(); // 先记录每个询问以离线处理

  maxp[rt] = sum = n; // 第一次先找整棵树的重心
  getrt(1, 0);
  solve(rt); // 对树进行点分治

  for (int i = 1; i <= m; ++i) {
    if (test[i])
      printf("AYE\n");
    else
      printf("NAY\n");
  }
  std::cout << totc << '\n';
  return 0;
}