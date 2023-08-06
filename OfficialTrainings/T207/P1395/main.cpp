#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

array<int, 50001> val, sz, weight;
array<int, 2> centeroid;
int n;

void getCenteroid(int u, int pa) {
  weight[u] = 0;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != pa) {
      getCenteroid(v, u);
      sz[u] += sz[v];
      weight[u] = max(weight[u], sz[v]);
    }
  }
  weight[u] = max(weight[u], n - sz[u]);
  if (weight[u] <= n / 2) {
    centeroid[centeroid[0] != 1 << 30] = u;
  }
}

long long getDist(int u, int pa, long long dep) {
  long long d = dep;
  for (int v : g[u]) {
    if (v != pa) {
      d += getDist(v, u, dep + 1);
    }
  }
  return d;
}

int main() {
  freopen("data.in", "r", stdin);
  centeroid.fill(0x7fffffff);
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  getCenteroid(1, 1);
  sort(centeroid.begin(), centeroid.end());
  int id = centeroid[0];

  cout << id << ' ' << getDist(id, id, 0);

  return 0;
}