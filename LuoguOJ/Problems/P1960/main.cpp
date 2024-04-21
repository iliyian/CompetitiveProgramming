#include <bits/stdc++.h>
using namespace std;

int in[5001];

vector<int> L;
vector<vector<int>> g;
queue<int> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, M;
  cin >> N >> M;
  memset(in, 0, sizeof(in));
  g.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    in[v]++;
  }
  int t = 0;
  bool f;
  for (int i = 1; i <= N; i++)
    if (in[i] == 0) {
      q.push(i);
      if (++t > 1) f = true;
    }
  t = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    L.push_back(u);
    t = 0;
    for (int v : g[u]) {
      if (!--in[v]) {
        if (++t > 1) f = true;
        // 1对1关系
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= N; i++)
    if (in[i])
      L.push_back(i);
  for (auto i : L)
    cout << i << '\n';
  cout << int(f);
  return 0;
}