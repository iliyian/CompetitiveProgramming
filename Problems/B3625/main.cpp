#include <bits/stdc++.h>
using namespace std;

char a[100][100];

struct Node {
  int x, y;
};
queue<Node> q;

bitset<100> vis[100];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  q.push({0, 0});
  vis[0][0] = true;
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y;
    if (x == n - 1 && y == m - 1) {
      cout << "Yes";
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy] || a[xx][yy] == '#') continue;
      vis[xx][yy] = true;
      q.push({xx, yy}); 
    }
  }
  cout << "No";
  return 0;
}