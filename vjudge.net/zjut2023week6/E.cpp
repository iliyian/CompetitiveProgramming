#include <bits/stdc++.h>
#define N 1005
using namespace std;

bitset<N> a[N];
vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    a[u][v] = a[v][u] = true;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cout << a[i][j] << " \n"[j == n];
  for (auto u : g) {
    if (u.empty()) continue;
    cout << u.size() << ' ';
    sort(u.begin(), u.end());
    for (auto v : u)
      cout << v << ' ';
    cout << '\n';
  }
}