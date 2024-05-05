// date: 2024-05-04 14:52:07
// tag: 二分，拓扑排序

#include <bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }

  };

  auto check = [&](int mid) {
    vector<int> in(n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] <= mid) {
        for (int v : g[i]) {
          if (a[v] <= mid) {
            in[v]++;
          }
        }
      }
    }
    queue<int> q;
    vector<int> dis(n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] <= mid && !in[i]) {
        q.push(i);
        dis[i] = 1;
      }
    }
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : g[u]) {
        if (a[v] <= mid && !--in[v]) {
          q.push(v);
          dis[v] = dis[u] + 1;
        }
      }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= mid) {
        if (in[i]) {
          return true;
        }
        mx = max(mx, dis[i]);
      }
    }
    return mx >= k;
  };

  int l = 1, r = (int)1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << '\n';

  return 0;
}