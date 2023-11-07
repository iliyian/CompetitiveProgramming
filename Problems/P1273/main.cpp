// tag: 树上分组背包模板
// re#01: 又是改了N便于调试但是忘改回去

#include <bits/stdc++.h>
#define N 3001
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

int f[N][N], val[N], n, m;

int dfs(int u) {
  int sum = 0;
  if (u > n - m) {
    f[u][1] = val[u];
    return 1;
  }
  for (auto &ed : g[u]) {
    int v = ed.v, w = ed.w;
    int t = dfs(v);
    sum += t;
    for (int j = sum; j > 0; j--) {
      for (int i = 1; i <= t; i++) {
        if (j >= i)
          f[u][j] = max(f[u][j], f[u][j - i] + f[v][i] - w);
      }
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  cin >> n >> m;
  memset(f, -0x3f, sizeof(f));
  g.resize(n + 1);
  for (int i = 1; i < 1 + n - m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a, c;
      cin >> a >> c;
      g[i].push_back({a, c});
    }
  }
  for (int i = n - m + 1; i <= n; i++)
    cin >> val[i];
  // entrance
  for (int i = 1; i <= n; i++)
    f[i][0] = 0;

  dfs(1);
  for (int i = m; i >= 1; i--) {
    if (f[1][i] >= 0) {
      cout << i;
      break;
    }
  }
  return 0;
}