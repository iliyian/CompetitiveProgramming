#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<vector<int>> f(m + 1);
  for (int i = 1; i <= m; i++) {
    int k;
    cin >> k;
    f[i].push_back(k);
    if (k == 1) {
      int p, v;
      cin >> p >> v;
      f[i].push_back(p);
      f[i].push_back(v);
    } else if (k == 2) {
      int v;
      cin >> v;
      f[i].push_back(v);
    } else {
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        f[i].push_back(x);
      }
    }
  }
  int q;
  cin >> q;
  vector<vector<int>> g(m + 2);
  vector<int> in(m + 2);
  for (int i = 1; i <= q; i++) {
    g[1].
  }         

  return 0;
}