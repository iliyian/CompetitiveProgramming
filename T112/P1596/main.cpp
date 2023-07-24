#include <bits/stdc++.h>
using namespace std;

bool field[101][101], vis[101][101];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Pos {
  int x, y;
};

queue<Pos> q;

int main() {
  freopen("data.in", "r", stdin);

  int n, m, sx, sy;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    memset(vis[i], 0, sizeof(vis[i]));
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      field[i][j] = ch == 'W';
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || !field[i][j]) continue;
      q.push(Pos{i, j});
      while (!q.empty()) {
        Pos u = q.front(); q.pop();
        if (u.x < 0 || u.x >= n || u.y < 0 || u.y >= m || vis[u.x][u.y] || !field[u.x][u.y]) continue;
        vis[u.x][u.y] = 1;
        for (int i = 0; i < 8; i++)
          q.push(Pos{u.x + dx[i], u.y + dy[i]}); 
      }
      ans++;
    }
  }
  cout << ans;
  return 0;
}