// floyd非得用邻接矩阵不可,邻接表e的索引不是边的编号

#include <bits/stdc++.h>
using namespace std;

// struct Edge {
//   int v, w;
// };

// vector<vector<Edge>> e;
int dis[201][201], tneed[201], n, m;
const int inf = 1 << 30;

void floyd(int k) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (dis[i][j] - dis[i][k] > dis[k][j])
        dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  // e.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> tneed[i];
    for (int j = 0; j < n; j++)
      dis[i][j] = inf;
    dis[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    // e[u].push_back({v, w});
    // e[v].push_back({u, w});
    dis[u][v] = dis[v][u] = w;
  }

  int q, curk = 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    
    while (tneed[curk] <= t && curk < n) {
      floyd(curk++);
    }

    if (curk-1 < x || curk-1 < y || dis[x][y] == inf) cout << -1 << '\n';
    else cout << dis[x][y] << '\n';
  }
  return 0;
}