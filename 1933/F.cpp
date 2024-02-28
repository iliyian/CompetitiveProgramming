#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int x, y, realx, realy, t;
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  queue<Node> q;
  q.push({0, 0, 0, 0, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    int rx = node.realx, ry = node.realy;
    if (rx == n - 1 && ry == m - 1) {
      cout << t << '\n';
      return;
    }
    if (vis[x][y]) continue;
    vis[x][y] = true;
    int x1 = (x + 1) % n, x2 = (x + 2) % n;
    if (!a[x1][y] && !a[x2][y]) {
      q.push({x2, y, x1, y, t + 1});
    }
    if (!a[x1][y]) {
      q.push({(x - 1 + n) % n, y, x, y, t + 1});
    }
    int y1 = y + 1, y2 = y - 1;
    if (y1 >= 0 && y1 < m && !a[x1][y1]) {
      q.push({x1, y1, x, y1, t + 1});
    }
    if (y2 >= 0 && y2 < m && !a[x1][y2]) {
      q.push({x1, y2, x, y2, t + 1});
    }
  }
  cout << -1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}