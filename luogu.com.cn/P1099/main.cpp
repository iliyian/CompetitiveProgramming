// date: 2024/02/04 15:40:36
// tag: 树的直径的运用
// wa#01: dfs过程中求出的dep本身就是个前缀和，关于节点而非节点dfs序的
// 最近总是写混序和值，线段树也是
// 顺便如果dfs的pa放循环里面，第40行需要加 pa[c] = 0才能过，（应该？
// 反正肯定能改出来的吧

#include <bits/stdc++.h>
#define N 305
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;
bitset<N> is_dia;
int dep[N], c = 0, pa[N], dia[N], pre[N];

void dfs(int u, int prv) {
  pa[u] = prv;
  for (auto [v, w] : g[u]) {
    if (v == prv || is_dia[v]) continue;
    dep[v] = dep[u] + w;
    if (dep[v] > dep[c]) c = v;
    dfs(v, u);
  }
}

void solve() {
  int n, s;
  cin >> n >> s;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  
  dfs(1, 0);
  dep[c] = 0;
  int cnt = 0;
  dfs(c, 0);

  for (int u = c; u; u = pa[u]) {
    dia[++cnt] = u;
    pre[u] = dep[u];
  }
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= cnt; i++) {
    for (int j = i; j <= cnt; j++) { // 点核
      if (pre[dia[i]] - pre[dia[j]] > s) continue;
      int ecc = 0;
      is_dia.reset();
      for (int k = i; k <= j; k++) is_dia[dia[k]] = true;
      for (int k = i; k <= j; k++) {
        dep[dia[k]] = 0, c = dia[k];
        dfs(dia[k], 0);
        ecc = max(ecc, dep[c]);
      }
      ans = min(ans, ecc);
    }
  }
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