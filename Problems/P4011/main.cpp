// date: 2024-04-05 18:33:25
// tag: 状态压缩

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, p;
  cin >> n >> m >> p;
  int k;
  cin >> k;
  map<tuple<int, int, int, int>, int> door;
  for (int i = 1; i <= k; i++) {
    int x1, y1, x2, y2, t;
    cin >> x1 >> y1 >> x2 >> y2 >> t;
    if (t == 0) t = -1;
    door[{x1, y1, x2, y2}] = door[{x2, y2, x1, y1}] = 1 << t - 1;
  }
  int s;
  cin >> s;
  map<tuple<int, int>, int> key;
  map<tuple<int, int, int>, bool> vis;
  for (int i = 1; i <= s; i++) {
    int x, y, q;
    cin >> x >> y >> q;
    key[{x, y}] |= 1 << q - 1;
  }
  queue<tuple<int, int, int, int>> q;
  q.push({1, 1, 0, 0});
  vis[{1, 1, 0}] = true;

  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  while (!q.empty()) {
    auto [x, y, k, t] = q.front(); q.pop();
    k |= key[{x, y}];
    if (x == n && y == m) {
      cout << t << '\n';
      return 0;
    }
    for (int i = 0 ; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!in(xx, yy) || vis[{xx, yy, k}]) continue;
      int g = door[{x, y, xx, yy}];
      if (g == -1) continue;
      if (g == 0 || k & g) {
        q.push({xx, yy, k, t + 1});
        vis[{xx, yy, k}] = true;
      }
    }
  }
  cout << -1 << '\n';

  return 0;
}