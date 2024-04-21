#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {return w > b.w;}
};
priority_queue<Edge> q;

int pa[10001];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    q.push({u, v, w});
  }
  for (int i = 1; i <= n; i++) pa[i] = i;
  int ans = -1;
  while (!q.empty()) {
    Edge e = q.top(); q.pop();
    int u = e.u, v = e.v;
    // if (find(u) == find(v)) {
    //   if (u == s && v == t || u == t && v == s) {
    //     cout << ans;
    //     return 0;
    //   }
    // } else {
    if (find(u) != find(v)) {
      pa[find(u)] = find(v);
    }
    if (find(s) == find(t)) {
      cout << e.w;
      return 0;
    }
  }
  return 0;
}
