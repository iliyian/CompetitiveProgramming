// date: 2024-05-18 23:41:10
// tag: dp

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> X(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> X[i];
  }
  int tot = 0;
  vector<vector<array<int, 2>>> row(n + 1);
  vector<array<int, 2>> to(k * 2 + 3);
  row[1].push_back({1, tot++});
  for (int i = 1; i <= k; i++) {
    int x1, y1, x2, y2, h;
    cin >> x1 >> y1 >> x2 >> y2 >> h;
    row[x1].push_back({y1, tot++});
    row[x2].push_back({y2, tot++});
    to[tot - 2] = {tot - 1, h};
  }
  row[n].push_back({m, tot++});
  vector<int> f(tot, -inf);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    sort(row[i].begin(), row[i].end());
    for (int j = 1; j < row[i].size(); j++) {
      f[row[i][j][1]] = max(f[row[i][j][1]], f[row[i][j - 1][1]] - X[i] * abs(row[i][j][0] - row[i][j - 1][0]));
    }
    for (int j = row[i].size() - 2; j >= 0; j--) {
      f[row[i][j][1]] = max(f[row[i][j][1]], f[row[i][j + 1][1]] - X[i] * abs(row[i][j + 1][0] - row[i][j][0]));
    }
    for (auto [y, id] : row[i]) {
      if (f[id] != -inf) { // 这里不会自动失效
        f[to[id][0]] = max(f[to[id][0]], f[id] + to[id][1]);
      }
    }
  }
  if (f[tot - 1] == -inf) {
    cout << "NO ESCAPE\n";
  } else {
    cout << -f[tot - 1] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}