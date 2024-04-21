#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> e;
vector<int> cows;
int cnt[1001];
bitset<1001> vis;

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  cnt[u]++;
  for (auto v : e[u]) {
    dfs(v);
  }
}

int main() {
  freopen("data.in", "r", stdin);
  int k, n, m;
  cin >> k >> n >> m;
  e.resize(n + 1);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < k; i++) {
    int cow;
    cin >> cow;
    cows.push_back(cow);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
  }
  for (auto u : cows) {
    dfs(u);
    vis.reset();
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[i] == k;
  }
  cout << ans;
  return 0;
}