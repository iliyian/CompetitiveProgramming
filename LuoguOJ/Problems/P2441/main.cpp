// 这题DFS更合理

#include <bits/stdc++.h>
using namespace std;

int a[200001];

vector<vector<int>> g;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int bfs(int u) {
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    int t = q.front(); q.pop();
    for (auto v : g[t]) {
      if (gcd(a[u], a[v]) > 1) {
        return v;
      }
      q.push(v);
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[y].push_back(x);
  }
  for (int i = 0; i < k; i++) {
    int op, u, w;
    cin >> op >> u;
    if (op == 1) {
      cout << bfs(u) << '\n';
    } else {
      cin >> w;
      a[u] = w;
    }
  }
  return 0;
}