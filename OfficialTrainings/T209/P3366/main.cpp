#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {return w > b.w;}
};
priority_queue<Edge> q;

int pa[5001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    q.push({u, v, w});
  }
  int ans = 0, count = 0;
  while (!q.empty()) {
    Edge e = q.top(); q.pop();
    int u = e.u, v = e.v;
    if (find(u) != find(v)) {
      pa[find(u)] = find(v);
      ans += e.w;
      count++;
    }
  }
  if (count == n - 1) cout << ans;
  else cout << "orz";
  return 0;
}