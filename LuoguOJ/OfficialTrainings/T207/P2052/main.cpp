// 未来人类或许直接 #define int long long

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

vector<vector<Edge>> g;
long long sz[1000001], ans = 0, n;

void dfs(int u, int pa) {
  sz[u] = 1;
  for (auto &ed : g[u]) {
    int v = ed.v, w = ed.w;
    if (v != pa) {
      dfs(v, u);
      sz[u] += sz[v];
      ans += w * abs(2 * sz[v] - n);
    }
  }
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  dfs(1, 1);
  cout << ans;
  return 0;
}