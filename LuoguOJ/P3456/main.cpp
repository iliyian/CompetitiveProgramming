#include <bits/stdc++.h>
using namespace std;

int a[1000][1000], n;
bitset<1000> vis[1000];

struct Node {
  int x, y;
};
queue<Node> q, sub;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int vcnt = 0, pcnt = 0;

void bfs(int sx, int sy) {
  q.push({sx, sy});
  bool isvalley = true, ispeak = true;
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y;

    if (a[x][y] != a[sx][sy]) {
      if (a[x][y] < a[sx][sy])
        isvalley = false;
      if (a[x][y] > a[sx][sy])
        ispeak = false;
      continue;
    }
    if (vis[x][y]) continue;
    vis[x][y] = true;

    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
      q.push({xx, yy});
    }
  }
  if (ispeak ^ isvalley)  
    vcnt += isvalley, pcnt += ispeak;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!vis[i][j])
        bfs(i, j), cnt++;
  if (cnt == 1) cout << "1 1";
  else cout << pcnt << ' ' << vcnt;
  return 0;
}