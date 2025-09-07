#include <bits/stdc++.h>
using namespace std;
int t;
int n, a[400005];
vector<int> g[400005];
int sz[400005], dep[400005], son[400005], fa[400005], top[400005];
void dfs1(int v) {
  sz[v] = 1;
  dep[v] = dep[fa[v]] + 1;
  for (auto to : g[v])
    if (to != fa[v]) {
      fa[to] = v;
      dfs1(to);
      sz[v] += sz[to];
      if (sz[to] > sz[son[v]])
        son[v] = to;
    }
}
void dfs2(int v) {
  if (son[v])
    top[son[v]] = top[v], dfs2(son[v]);
  for (auto to : g[v])
    if (to != fa[v] && to != son[v]) {
      top[to] = to;
      dfs2(to);
    }
}
inline int LCA(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] > dep[top[y]])
      x = fa[top[x]];
    else
      y = fa[top[y]];
  }
  if (dep[x] < dep[y])
    return x;
  else
    return y;
}
inline int LST(int x, int y) {
  while (top[x] != top[y]) {
    if (fa[top[x]] == y)
      return top[x];
    else
      x = fa[top[x]];
  }
  return son[y];
}
int S[200005], T[200005];
int d[400005];
void dfs3(int v) {
  for (auto to : g[v])
    if (to != fa[v]) {
      d[to] += d[v];
      dfs3(to);
    }
}
int ans[400005];
bool vis[400005];
queue<int> q;
set<int> K, L;
void clear() {
  for (int i = 1; i <= n + n; ++i)
    ans[i] = d[i] = sz[i] = dep[i] = fa[i] = son[i] = top[i] = 0, g[i].clear();
  for (int i = 1; i <= n; ++i)
    S[i] = T[i] = 0;
  K.clear();
  L.clear();
  while (!q.empty())
    q.pop();
  for (int i = 1; i <= n + n; ++i)
    vis[i] = 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n + n; ++i) {
      cin >> a[i];
      if (a[i] >= 0)
        S[a[i]] = i;
      else
        T[-a[i]] = i;
    }
    for (int i = 1, x, y; i < n + n; ++i) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs1(1);
    top[1] = 1;
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
      int L = LCA(S[i], T[i]);
      //			cout<<"S="<<S[i]<<" T="<<T[i]<<" L="<<L<<"\n";
      if (L != T[i]) {
        ++d[1];
        --d[T[i]];
        //				cout<<"++d["<<1<<"]\n";
        //				cout<<"--d["<<T[i]<<"]\n";
      } else {
        ++d[LST(S[i], T[i])];
        //				cout<<"++d["<<LST(S[i],T[i])<<"]\n";
      }
    }
    dfs3(1);
    //		for(int i=1;i<=n+n;++i) cout<<d[i]<<" ";
    //		cout<<"\n";
    int st = 0;
    for (int i = 1; i <= n; ++i)
      ans[i] = 0;
    for (int i = 1; i <= n + n; ++i) {
      if (d[i] == n)
        ans[a[i]] = 1, st = i;
    }
    if (!st) {
      for (int i = 1; i <= n; ++i)
        cout << "0";
      cout << "\n";
      clear();
      continue;
    }
    vis[st] = 1;
    q.push(st);
    K.insert(a[st]);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto to : g[v]) {
        if (vis[to])
          continue;
        if (a[to] > 0) {
          vis[to] = 1;
          q.push(to);
          K.insert(a[to]);
          if (L.find(a[to]) != L.end()) {
            vis[T[a[to]]] = 1;
            q.push(T[a[to]]);
          }
        } else {
          if (K.find(-a[to]) != K.end()) {
            vis[to] = 1;
            q.push(to);
          } else {
            L.insert(-a[to]);
          }
        }
      }
    }
    bool flag = 1;
    for (int i = 1; i <= n + n; ++i)
      if (!vis[i])
        flag = 0;
    if (!flag) {
      for (int i = 1; i <= n; ++i)
        cout << "0";
      cout << "\n";
      clear();
      continue;
    }
    for (int i = 1; i <= n; ++i)
      cout << ans[i];
    cout << "\n";
    clear();
  }
  return 0;
}