// date: 2024/02/01 13:03:39
// tag: wa#01: 看似差分约束，实则缩点+拓扑排序
// 由小向大建边即可，spfa太弱了，对于这个数据范围
// 缩点后的DAG拥有很多良好性质

// i <- j
// \   /
//  \ /
//   o

// xi <= xj + ji, 边oi最短，且无负环

#include <bits/stdc++.h>
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g, sg;

int dfn[N], low[N], scc[N], scc_no = 0, cnt = 0, in[N], f[N], siz[N];
bitset<N> ins;
stack<int> st;

void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  ins[u] = true;
  st.push(u);
  for (auto [v, w] : g[u]) {
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
      siz[scc_no]++;
      if (x == u) break;
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int x, a, b;
    cin >> x >> a >> b;
    if (x == 1) {
      g[a].push_back({b, 0}), g[b].push_back({a, 0});
    } else if (x == 2) { // a < b
      g[a].push_back({b, 1});
    } else if (x == 3) { // a >= b, b <= a + 0
      g[b].push_back({a, 0});
    } else if (x == 4) { // a >= b + 1, b<= a - 1
      g[b].push_back({a, 1});
    } else { // a <= b + 0
      g[a].push_back({b, 0});
    }
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);
  
  sg.resize(scc_no + 1);
  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : g[u]) {
      if (scc[v] == scc[u] && w == 1) {
        cout << "-1\n";
        return;
      }
      if (scc[v] != scc[u]) {
        sg[scc[u]].push_back({scc[v], w});
        in[scc[v]]++;
      }
    }
  }
  queue<int> q;
  for (int i = 1; i <= scc_no; i++)
    if (!in[i]) {
      q.push(i);
      f[i] = 1;
    }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto [v, w] : sg[u]) {
      f[v] = max(f[v], f[u] + w);
      if (!--in[v]) q.push(v);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= scc_no; i++)
    ans += 1ll * siz[i] * f[i];
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