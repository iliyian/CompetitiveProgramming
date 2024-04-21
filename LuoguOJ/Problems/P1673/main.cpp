#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

struct Node {
  int u, cnt;
  bool operator < (const Node &b) const {
    return cnt > b.cnt;
  }
};

priority_queue<Node> q;
bitset<1001> vis;

int main() {
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  g.resize(k + 1);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  q.push({1, 1});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, cnt = node.cnt;
    if (u == k) {
      cout << cnt;
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (auto v : g[u]) {
      q.push({v, cnt + 1});
    }
  }
  cout << -1;
}