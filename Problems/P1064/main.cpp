#include <bits/stdc++.h>
using namespace std;

int v[61], w[61], q[61], f[32001];

vector<vector<int>> g, belong;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(m + 1);
  belong.resize(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> w[i] >> v[i] >> q[i];
    v[i] *= w[i];
    if (q[i])
      g[q[i]].push_back(i), belong[i].push_back(q[i]);
  }
  memset(f, -0x3f, sizeof(f));
  f[0] = 0;
  int ans = -0x3f3f3f3f;
  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= 0; j--) {
      if (belong[i].empty()) {
        int ww = w[i], vv = v[i];
        if (j >= ww)
          f[j] = max(f[j], f[j - ww] + vv);
        if (g[i].size() >= 1) {
          ww += w[g[i][0]], vv += v[g[i][0]];
          if (j >= ww)
            f[j] = max(f[j], f[j - ww] + vv);
        }
        if (g[i].size() >= 2) {
          ww += w[g[i][1]], vv += v[g[i][1]];
          if (j >= ww)
            f[j] = max(f[j], f[j - ww] + vv);
          ww = w[i] + w[g[i][1]], vv = v[i] + v[g[i][1]];
          if (j >= ww)
            f[j] = max(f[j], f[j - ww] + vv);
        }
      }
      ans = max(ans, f[j]);
    }
  }
  cout << ans;
  return 0;
}