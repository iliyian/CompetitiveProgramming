#include <bits/stdc++.h>
#define N 100005
using namespace std;

int dep[N];
vector<vector<int>> g;

void dfs(int u, int p) {
  dep[u] = dep[p] + 1;
  for (int v : g[u])
    if (v != p)
      dfs(v, u);
}

void solve() {
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  double ans = 0;
  dfs(1, 0);
  for (int i = 1; i <= n; i++)
  // 在序列中仅考虑存在i和i的所有祖先的情况，则i打头的概率为1/dep[i];
    ans += 1.0 / dep[i];
  cout << fixed << setprecision(20) << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}