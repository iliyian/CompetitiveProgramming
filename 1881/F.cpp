// date: 2023/12/15
// tag: 树的直径，离线操作比大小

#include <bits/stdc++.h>
#define N 200005
using namespace std;

vector<vector<int>> g;
bitset<N> marked;
int d[N];

void dfs(int u, int prev) {
  d[u] = d[prev] + 1;
  for (int v : g[u])
    if (v != prev)
      dfs(v, u);
}

void solve() {
  int n, k;
  cin >> n >> k;
  g.clear();
  g.resize(n + 1);
  marked.reset();
  vector<int> marks;
  for (int i = 0; i < k; i++) {
    int x; cin >> x;
    marks.push_back(x);
    marked[x] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(marks[0], 0);
  int tgt = 0;
  for (int i : marks)
    if (d[i] > d[tgt])
      tgt = i;
  d[tgt] = 0;
  dfs(tgt, 0);
  tgt = 0;
  for (int i : marks)
    if (d[i] > d[tgt])
      tgt = i;
  cout << (d[tgt]) / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}