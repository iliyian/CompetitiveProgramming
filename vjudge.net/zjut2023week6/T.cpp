#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

int pa[N];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}
void merge(int x, int y) {pa[find(x)] = find(y);}

struct Edge {
  int u, v, w;
} edges[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("T.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, v, w};
  }
  iota(pa + 1, pa + 1 + n, 1);
  sort(edges, edges + m, [](const Edge &a, const Edge &b) {
    return a.w < b.w;
  });
  int cnt = 0, sum = 0;
  for (auto &[u, v, w] : edges) {
    if (find(u) != find(v)) merge(u, v), cnt++, sum += w;
  }
  if (cnt == n - 1)
    cout << sum;
  else cout << "orz";
}