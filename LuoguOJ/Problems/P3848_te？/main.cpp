#include <bits/stdc++.h>
using namespace std;

bitset<100> vis[100], a[100];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int ans = -1, n, sx, sy;

// sum is pre
void dfs(int x, int y, int sum) {
  ans = max(ans, sum);
  for (int i = 0; i < 4; i++) {
    for (int j = 2;; j++) {
      int xx = x + dx[i] * j, yy = y + dy[i] * j;
      if (xx < 0 || xx >= n || yy < 0 || yy >= n) break;
      if (!a[xx][yy]) {
        if (!vis[xx][yy]) {
          vis[xx][yy] = true;
          dfs(xx, yy, sum + j);
          vis[xx][yy] = false;
        }
        break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> sx >> sy;
  sx--, sy--;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      a[i][j] = k;
    }

  vis[sx][sy] = true;
  dfs(sx, sy, 0);

  cout << ans;
  return 0;
}