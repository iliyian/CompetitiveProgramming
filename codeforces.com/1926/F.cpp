// date: 2024-02-27 11:53:37
// tag: 纯粹暴力dfs

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, -1, 1, 1, 0}, dy[] = {-1, 1, 1, -1, 0};

void solve() {
  vector<string> a(7);
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  int ans = 0, cur = 0;
  for (int t = 0; t < 2; t++) {
    cur = 4;
    auto dfs = [&](auto self, int x, int y, int z) -> void {
      if (x == 6) {
        cur = min(cur, z);
        return;
      }
      if (y == 6) {
        self(self, x + 1, 1, z);
        return;
      }
      if ((x + y) % 2 != t) {
        self(self, x, y + 1, z);
        return;
      }
      bool f = true;
      for (int i = 0; i < 5; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (a[xx][yy] == 'W') {
          self(self, x, y + 1, z);
          f = false;
          break;
        }
      }
      if (f) {
        for (int i = 0; i < 5; i++) {
          int xx = x + dx[i], yy = y + dy[i];
          a[xx][yy] = 'W';
          self(self, x, y + 1, z + 1);
          a[xx][yy] = 'B';
        }
      }
    };
    dfs(dfs, 1, 1, 0);
    ans += cur;
  }
  cout << ans << '\n';
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