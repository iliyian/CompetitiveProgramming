#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
int r[6001], dp[6001][2];
bitset<6001> isnt_root, vis;

void cal(int u) {
  vis[u] = true;
  for (auto v : edges[u]) {
    if (vis[v]) continue;
    cal(v);
    dp[u][1] += dp[v][0];
    dp[u][0] += max(dp[v][0], dp[v][1]);
  }
}

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  edges.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> dp[i][1];
  for (int i = 0; i < n; i++) {
    int l, k;
    cin >> l >> k;
    edges[k].push_back(l);
    isnt_root[l] = true;
  }
  for (int i = 1; i <= n; i++)
    if (!isnt_root[i]) {
      cal(i);
      cout << max(dp[i][0], dp[i][1]);
      return 0;
    }
}