#include <bits/stdc++.h>
#define N 2005
using namespace std;

struct Edge {
  int v, w;
};

class SPFA {
  public:

  vector<vector<Edge>> g;
  queue<int> q;
  bitset<N> vis;
  int dis[N], cnt[N], n, m;

  void solve() {
    q.push(1);
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    dis[1] = 0, vis[1] = true;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = false;
      for (auto &[v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          if (++cnt[v] == n) {
            cout << "YES\n";
            return;
          }
          if (!vis[v]) q.push(v), vis[v] = true;
        }
      }
    }
    cout << "NO\n";
  }
} spfa;

void solve() {
  spfa = SPFA{};
  cin >> spfa.n >> spfa.m;
  spfa.g.resize(spfa.n + 1);
  for (int i = 0; i < spfa.m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    spfa.g[u].push_back({v, w});
    if (w >= 0) spfa.g[v].push_back({u, w});
  }
  spfa.solve();
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("R.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}