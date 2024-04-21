#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int a[300005];
bitset<300005> vis;

void dfs(int u, int prev, int cnt) {
  vis[u] = cnt > 0;
  for (auto v : g[u]) {
    if (v == prev) continue;
    dfs(v, u, max(cnt - 1, a[v]));
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int N, M;
  cin >> N >> M;
  g.resize(N + 1);
  for (int i = 2; i <= N; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    a[x] = max(a[x], y + 1);
  }
  dfs(1, 0, a[1]);
  cout << vis.count();
  return 0;
}