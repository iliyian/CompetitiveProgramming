#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int f[301][302], N, M;

void dfs(int u) {
  for (int v : g[u]) {
    dfs(v);
    for (int j = M + 1; j >= 1; j--) {
      for (int k = 0; k < j; k++) {
        f[u][j] = max(f[u][j], f[v][k] + f[u][j - k]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> N >> M;
  g.resize(N + 1);
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= N; i++) {
    int k;
    cin >> k >> f[i][1];
    g[k].push_back(i);
  }
  f[0][1] = 0;
  dfs(0);
  cout << f[0][M + 1];
  return 0;
}