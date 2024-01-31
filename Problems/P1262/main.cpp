// date: 2024/01/31 16:36:34
// tag: 环就是一个强连通分量，真tmd巧妙
// 显然可以被背叛的不需要买，因此只买不可被背叛的

#include <bits/stdc++.h>
#define N 3005
#define inf 0x3f3f3f3f
using namespace std;

vector<vector<int>> g;
int price[N], dfn[N], low[N], in[N], scc[N], sccp[N];
int cnt = 0, scc_no = 0;
stack<int> st;
bitset<N> ins, cut, vis;

void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  ins[u] = true;
  st.push(u);
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
      ins[x] = false;
      scc[x] = scc_no;
      sccp[scc_no] = min(sccp[scc_no], price[x]);
      if (x == u) break;
    }
  }
}

void solve() {
  int n, p;
  cin >> n >> p;
  g.resize(n + 1);
  fill(price + 1, price + n + 1, inf);
  fill(sccp + 1, sccp + n + 1, inf);
  for (int i = 0; i < p; i++) {
    int x, y;
    cin >> x >> y;
    price[x] = y;
  }
  int r;
  cin >> r;
  for (int i = 0; i < r; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i] && price[i] != inf) {
      tarjan(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!scc[i]) {
      cout << "NO\n" << i << '\n';
      return;
    }
  }
  cout << "YES\n";
  for (int u = 1; u <= n; u++)
    for (int v : g[u])
      if (scc[u] != scc[v])
        in[scc[v]]++;
  int ans = 0;
  for (int i = 1; i <= scc_no; i++)
    if (!in[i])
      ans += sccp[i];
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}