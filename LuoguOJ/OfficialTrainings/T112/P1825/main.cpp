// 最简化原则
#include <bits/stdc++.h>
using namespace std;

struct Pos {
  int x, y, t;
  char tpd = 0;
};

queue<Pos> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bitset<305> vis[305];
char a[305][305];
map<char, pair<int, int>> tps1, tps2;

int main() {
  freopen("data.in", "r", stdin);
  int n, m, sx, sy;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (isalpha(a[i][j])) {
        if (tps1.count(a[i][j]))
          tps2[a[i][j]] = make_pair(i, j);
        else tps1[a[i][j]] = make_pair(i, j);
      }
      if (a[i][j] == '@') sx = i, sy = j;
    }
  }
  q.push(Pos{sx, sy, 0});
  while (!q.empty()) {
    Pos u = q.front(); q.pop();
    if (u.x < 0 || u.x >= n || u.y < 0 || u.y >= m || a[u.x][u.y] == '#' || vis[u.x][u.y]) continue;
    vis[u.x][u.y] = true;
    if (a[u.x][u.y] == '=') {
      cout << u.t;
      return 0;
    }
    if (isalpha(a[u.x][u.y])) {
      char ch = a[u.x][u.y];
      if (tps1[ch].first == u.x && tps1[ch].second == u.y)
        u.x = tps2[ch].first, u.y = tps2[ch].second;
      else u.x = tps1[ch].first, u.y = tps1[ch].second;      
    }
    for (int i = 0; i < 4; i++)
      q.push(Pos{u.x + dx[i], u.y + dy[i], u.t + 1});   
  }
  cout << -1;
  return 0;
}