// 递推方向取决于可知状态的位置

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

bitset<100001> vis;
int in[100001], n, m, dg[100001];
double f[100001];

void toposort() {
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto &ed: g[u]) {
      int v = ed.v, w = ed.w;
      f[v] += (f[u] + w) / dg[v];
      if (!--in[v]) q.push(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  memset(in, 0, sizeof(in));
  memset(f, 0, sizeof(f));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[v].push_back({u, w});
    in[u]++;
  };
  for (int i = 1; i <= n; i++)
    dg[i] = in[i];

  toposort();

  cout << fixed << setprecision(2) << f[1];
  return 0;
}