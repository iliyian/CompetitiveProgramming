// floyd 优化终究没有n次dijkstra快 O(mn^2) vs O(nmlogm)
// dis[i][i] = 0 很重要

#include <bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;

array<array<long long, 101>, 101> dis;

int N, M;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) 
    dis[i].fill(inf), dis[i][i] = 0;
  for (int i = 0; i < M; i++) {
    int op, s, t, e;
    cin >> op >> s >> t;
    if (op) {
      cin >> e;
      dis[s][t] = min(dis[s][t], (long long)e);
      dis[t][s] = dis[s][t];
      if (e > dis[s][t]) continue;
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
          dis[i][j] = dis[j][i] =
            min(dis[i][j], min(
              dis[i][s] + dis[s][t] + dis[t][j],
              dis[i][t] + dis[t][s] + dis[s][j]
            ));
    } else {
      cout << (dis[s][t] == inf ? -1 : dis[s][t]) << '\n';
    }
  }
  return 0;
}