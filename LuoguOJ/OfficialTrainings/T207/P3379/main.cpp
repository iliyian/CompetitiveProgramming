#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, i, lca;
  bool operator < (const Edge &b) const {return i < b.i;}
};

vector<Edge> ans;
vector<vector<int>> g;
vector<vector<Edge>> q;
bitset<500001> vis;

int pa[500001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

void tarjan(int u, int parent) {
  pa[u] = u;
  for (int v : g[u]) {
    if (v != parent) {
      tarjan(v, u);
      pa[find(v)] = u;
      vis[v] = true;
    }
  }
  for (auto ed : q[u]) {
    if (vis[ed.v]) {
      ed.lca = find(ed.v);
      ans.push_back(ed);
    }
  }
}

int main() {
  freopen("data.in", "r", stdin);
  int n, m, s;
  cin >> n >> m >> s;
  g.resize(n + 1);
  q.resize(n + 1);
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x == y) {ans.push_back({y, i, x}); continue;}
    q[x].push_back({y, i});
    q[y].push_back({x, i});
  }
  tarjan(s, s);
  sort(ans.begin(), ans.end());
  for (auto ed : ans) {
    cout << ed.lca << '\n';
  }
  return 0;
}