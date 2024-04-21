#include <bits/stdc++.h>
#define N 1005
using namespace std;

vector<vector<int>> g;
int in[N];
bitset<N> vis;

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  cout << u << ' ';
  for (int v : g[u])
    dfs(v);
}

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    in[v]++, in[u]++;
  }
  for (auto &ed : g)
    sort(ed.begin(), ed.end());
  int s = -1;
  for (int i = 1; i <= n; i++)
    if (in[i] & 1) {
      s = i;
      break;
    }
  if (s != -1) {
    dfs(s);
  } else {
    dfs(1);
    cout << 1;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("10.in", "r", stdin);
  freopen("10.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}