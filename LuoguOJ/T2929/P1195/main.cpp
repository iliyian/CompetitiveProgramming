#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {return w < b.w;}
} edges[10001];

int pa[1001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;
  if (m < n - k) {
    cout << "No answer";
    return 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }
  for (int i = 1; i <= n; i++) pa[i] = i;
  
  sort(edges, edges + m);

  int ans = 0, cnt = 0;
  for (int i = 0; i < m; i++) {
    int u = edges[i].u, v = edges[i].v, w = edges[i].w;
    if (find(u) != find(v)) {
      ans += w;
      pa[find(u)] = find(v);
      ++cnt;
    }
    if (n - cnt == k) {
      cout << ans;
      return 0;
    }
  }
  return 0;
}