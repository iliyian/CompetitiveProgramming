// 不要假定某些数据是有序的

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int burnat[305][305];
bitset<305> vis[305];

struct Pos {
  int x, y, t;
};

bool inRange(int x, int y) {
  if (x < 0 || y < 0) return false;
  return true;
}

queue<Pos> q;

int main() {
  freopen("data.in", "r", stdin);
  int M;
  cin >> M;
  for (int i = 0; i < 305; i++)
    for (int j = 0; j < 305; j++)
      burnat[i][j] = -1;
  for (int i = 0; i < M; i++) {
    int x, y, t;
    cin >> x >> y >> t;

    if (burnat[x][y] != -1) burnat[x][y] = min(burnat[x][y], t);
    else burnat[x][y] = t;
    for (int j = 0; j < 4; j++) {
      int x0 = x + dx[j], y0 = y + dy[j];
      if (inRange(x0, y0)) {
        int &b = burnat[x0][y0];
        if (b != -1) b = min(b, t);
        else b = t;
      };
    }
  }
  q.push(Pos{0, 0, 0});
  while (!q.empty()) {
    Pos u = q.front(); q.pop();
    if (!inRange(u.x, u.y) || vis[u.x][u.y]) continue;
    vis[u.x][u.y] = true;
    if (burnat[u.x][u.y] == -1) {
      cout << u.t;
      return 0;
    }
    if (u.t < burnat[u.x][u.y])
      for (int i = 0; i < 4; i++)
        q.push(Pos{u.x + dx[i], u.y + dy[i], u.t + 1});
  }
  cout << -1;
  return 0;
}