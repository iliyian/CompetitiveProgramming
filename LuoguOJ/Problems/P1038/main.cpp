// 21行的else完全凭灵感改的，这题题目没说清楚

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;
set<int> inputs, outputs;

int U[101], c[101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, p;
  cin >> n >> p;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> U[i];
    if (c[i]) inputs.insert(i);
    else c[i] -= U[i];
  }
  for (int i = 0; i < p; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  for (;;) {
    for (int u : inputs) {
      if (c[u] <= 0) continue;
      for (auto e : g[u]) {
        int v = e.v, w = e.w;
        c[v] += c[u] * w;
        outputs.insert(v);
      }
    }
    if (outputs.empty()) {
      bool f = false;
      for (int u : inputs) {
        if (c[u] > 0) {
          f = true;
          cout << u << ' ' << c[u] << '\n';
        }
      }
      if (!f) cout << "NULL";
      return 0;
    }
    inputs = outputs;
    outputs.clear();
  }
}