#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int low[5001], dfsn[5001], scc[5001], s[5001], sz[5001], tp = 0, cnt = 0, sc = 0;
bitset<5001> in_s;

bool cmp(const vector<int> &a, const vector<int> &b) {
  if (a.size() != b.size()) return a.size() > b.size();
  for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i])
      return a[i] > b[i];
  return false;
}

vector<vector<int>> vv;

void tarjan(int u) {
  dfsn[u] = low[u] = ++cnt;
  in_s[u] = true;
  s[++tp] = u;
  for (int v : g[u]) {
    if (!dfsn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_s[v])
      low[u] = min(low[u], dfsn[v]);
  }
  if (dfsn[u] == low[u]) {
    ++sc;
    vector<int> v;
    while (s[tp] != u) {
      v.push_back(s[tp]);
      in_s[s[tp]] = false;
      --tp;
    }
    v.push_back(s[tp]);
    in_s[s[tp]] = false;
    --tp;
    sort(v.begin(), v.end());
    vv.push_back(v);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  memset(dfsn, 0, sizeof(dfsn));
  memset(sz, 0, sizeof(sz));
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    g[u].push_back(v);
    if (t == 2) g[v].push_back(u);
  }

  int maxs = -1;
  for (int i = 1; i <= n; i++)
    if (!dfsn[i])
      tarjan(i);

  sort(vv.begin(), vv.end(), cmp);
  const vector<int> &v = vv.front();
  cout << v.size() << '\n';
  for (int i : v)
    cout << i << ' ';
  return 0;
}