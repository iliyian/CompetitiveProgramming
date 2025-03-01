// date: 2024/02/04 12:08:14
// tag: 缩点和树上背包
// wa#01: 背包动态规划的时候，
// 子节点也就是v的w的范围是[0, m-sw[u]]而不是[0, sw[u]]，
// 前者极大值是相当于所有子节点，后者极大值反而是父节点
// 循环的范围搞错了
// 同时由于scc_no从1开始，可以从0开始根据入度创建源点，但如果是原图就不行了，
// 原图本来就有0节点，除非不用

#include <bits/stdc++.h>
#define N 105
#define inf 0x3f3f3f3f
using namespace std;

vector<vector<int>> g, sg;

int dfn[N], low[N], scc[N], sv[N], sw[N], v[N], w[N], d[N], f[N][505], in[N];
int n, m, scc_no = 0, cnt = 0;
bitset<N> ins;
stack<int> st;

void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  st.push(u);
  ins[u] = true;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++scc_no;
    while (true) {
      int x = st.top(); st.pop();
      scc[x] = scc_no;
      sv[scc_no] += v[x];
      sw[scc_no] += w[x];
      ins[x] = false;
      if (x == u) break;
    }
  }
}

void dp(int u) {
  for (int i = sw[u]; i <= m; i++) f[u][i] = sv[u];
  for (int v : sg[u]) {
    dp(v);
    for (int i = m - sw[u]; i >= 0; i--)
      for (int j = 0; j <= i; j++)
        f[u][i + sw[u]] = max(f[u][i + sw[u]], f[v][j] + f[u][i + sw[u] - j]);
  }
}

void solve() {
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    g[d[i]].push_back(i);
  }
  for (int i = 0; i <= n; i++)
    if (!dfn[i])
      tarjan(i);
  sg.resize(scc_no + 1);

  for (int u = 0; u <= n; u++) {
    for (int v : g[u]) {
      if (scc[u] != scc[v]) {
        sg[scc[u]].push_back(scc[v]);
        in[scc[v]]++;
      }
    }
  }
  for (int i = 1; i <= scc_no; i++)
    if (!in[i])
      sg[0].push_back(i);

  dp(0);

  cout << f[0][m];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}