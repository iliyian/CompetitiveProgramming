#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {return w < b.w;}
};
vector<Edge> edges;

int pa[2001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    edges.push_back({v, u, w});
  }
  sort(edges.begin(), edges.end());
  int maxlen = -1, cnt = 0;
  for (const auto &ed : edges) {
    int u = ed.u, v = ed.v, w = ed.w;
    int pu = find(u), pv = find(v);
    if (cnt == n - 1) break;
    if (pu != pv) {
      pa[pu] = pv;
      cnt++;
      maxlen = max(maxlen, w);
    }
  }
  cout << maxlen;
  return 0;
}