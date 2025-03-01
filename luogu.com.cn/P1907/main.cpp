#include <bits/stdc++.h>
using namespace std;

double x[1002], y[1002], dis[1002];
bitset<1002> g[1002], vis;

struct Node {
  int u;
  double d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
priority_queue<Node> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  double A, B;
  cin >> A >> B;
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> x[i] >> y[i];
    dis[i] = double(1 << 30);
  }
  dis[N + 1] = double(1 << 30);
  int u, v;
  while (cin >> u >> v) {
    if (u == 0) break;
    g[u][v] = g[v][u] = true;
  }
  cin >> x[0] >> y[0] >> x[N + 1] >> y[N + 1];
  q.push({0, 0});
  dis[0] = 0;
  while (!q.empty()) {
    int u = q.top().u;
    double d = q.top().d; q.pop();
    if (u == N + 1) {
      cout << fixed << setprecision(4) << d;
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = 1; i <= N + 1; i++) {
      double dist = sqrt((x[i] - x[u]) * (x[i] - x[u]) + (y[i] - y[u]) * (y[i] - y[u]));
      double dd = (g[i][u] ? B * dist : A * dist);
      if (dis[i] > dis[u] + dd) {
        dis[i] = dis[u] + dd;
        q.push({i, dis[i]});
      }
    }
  }
  cout << -1;
  return 0;
}