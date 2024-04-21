// 本题中的点权，对于是否乘坐飞机，形成两种选择，也就是两条不同权的边，邻接表直接处理即可
// 我不懂vis数组什么用

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

priority_queue<int, vector<int>, greater<int>> q;
vector<int> L;
vector<vector<Edge>> e;
int dis[221], cnt[221];
int D, P, C, F, S;

int main() {
  freopen("data.in", "r", stdin);
  cin >> D >> P >> C >> F >> S;
  e.resize(C + 1);
  for (int i = 1; i <= C; i++) {
    cnt[i] = 0;
    dis[i] = 0;
  }

  for (int i = 0; i < P; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back({v, D});
  }
  for (int i = 0; i < F; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, D - w});
  }

  q.push(S);
  dis[S] = D;
  // vis[S] = true;
  while (!q.empty()) {
    int u = q.top(); q.pop();
    // vis[u] = true;
    for (auto ed : e[u]) {
      int v = ed.v;
      if (dis[v] < dis[u] + ed.w) {
        dis[v] = dis[u] + ed.w;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] >= C) {
          cout << -1;
          return 0;
        }
        q.push(v);
        // if (!vis[v]) q.push(v), vis[v] = true;
      }
    }
  }

  cout << *max_element(dis + 1, dis + C + 1);
  return 0;
}