#include <bits/stdc++.h>
using namespace std;

struct Node {
  int u, d;
};

vector<vector<int>> e;
queue<Node> que;
bitset<100005> vis;

int main() {
  freopen("data.in", "r", stdin);
  int n, d;
  cin >> n >> d;
  e.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  que.push({1, 0});
  int ans = -1;
  while (!que.empty()) {
    Node node = que.front(); que.pop();
    if (vis[node.u] || node.d > d) {
      continue;
    }
    ans++;
    vis[node.u] = true;
    for (int i = 0; i < e[node.u].size(); i++) {
      que.push({e[node.u][i], node.d + 1});
    }
  }
  cout << ans;
  return 0;
}