// date: 2024-04-30 12:00:06
// tag: 树，模拟

#include <bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }

  bitset<N + 1> vis;
  priority_queue<int> q;
  vector<int> a;
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    if (!vis[p]) {
      vis[p] = true;
      a.push_back(g[p].size());
    }
  };
  dfs(dfs, 1, 0);

  sort(a.begin(), a.end(), greater<int>());
  int d = 0, ans = 0;
  for (int i = 0; i < a.size(); i++) {
    q.push(a[i] - (a.size() - i - 1) - 1);
    ans++;
  }
  d = 0;
  while (!q.empty() && q.top() > d) {
    int u = q.top(); q.pop();
    d++;
    ans++;
    q.push(u - 1);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}