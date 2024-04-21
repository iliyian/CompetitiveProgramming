#include <bits/stdc++.h>
using namespace std;

int a[1001][1001], in[1001], n, m;
bitset<1001> vis;
vector<vector<int>> g;
vector<int> L;

struct Node {
  int u, lv = 0;
};
queue<Node> q;
int ans = -1;

void topo() {
  for (int i = 1; i <= n; i++)
    if (!in[i])
      q.push({i, 1});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int u = node.u, lv = node.lv;
    ans = max(ans, lv);
    L.push_back(u);
    for (int v : g[u])
      if (!--in[v])
        q.push({v, lv + 1});
  }
  cout << ans;
}
bitset<1001> topoed[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  memset(in, 0, sizeof(in));
  for (int i = 0; i < m; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      cin >> a[s][j];
      vis[a[s][j]] = true;
    }
    for (int u = a[s][0]; u <= a[s][s - 1]; u++)
      if (!vis[u])
        for (int k = 0; k < n; k++) {
          int v = a[s][k];
          if (!topoed[v][u])
            in[v]++, g[u].push_back(v), topoed[v][u] = true;
        }
    vis.reset();
  }
  topo();
  return 0;
}