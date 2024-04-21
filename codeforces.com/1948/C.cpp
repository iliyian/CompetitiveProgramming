#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n;
  cin >> n;
  vector<string> a(2);
  cin >> a[0] >> a[1];
  queue<pair<int, int>> q;
  q.push({0, 0});
  vector<vector<bool>> vis(2, vector<bool>(n));
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (y == n - 1) {
      cout << "YES\n";
      return;
    }
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= 2 || yy < 0 || yy >= n) continue;
      yy += (a[xx][yy] == '<' ? -1 : 1);
      q.push({xx, yy});
    }
  }
  cout << "NO\n";
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