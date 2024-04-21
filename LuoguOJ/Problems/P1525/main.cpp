#include <bits/stdc++.h>
using namespace std;

struct Node {
  int u, v, w;
  bool operator < (const Node &b) const {
    return w > b.w;
  }
};

int pa[20001], anti[20001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

void add(int u, int v) {
  pa[find(u)] = pa[v];
}

vector<Node> ve;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ve.push_back({u, v, w});
  }
  memset(anti, 0, sizeof(anti));
  for (int i = 1; i <= n; i++)
    pa[i] = i;
  sort(ve.begin(), ve.end());
  for (Node &node : ve) {
    int u = node.u, v = node.v, w = node.w;
    if (find(u) == find(v)) {
      cout << w;
      return 0;
    }
    // greedy
    if (anti[u]) add(anti[u], v);
    else anti[u] = v;
    if (anti[v]) add(anti[v], u);
    else anti[v] = u;
  }
  cout << 0;
  return 0;
}