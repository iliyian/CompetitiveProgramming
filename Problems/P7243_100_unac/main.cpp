#include <bits/stdc++.h>
using namespace std;

unsigned long long a[2000][2000];
bitset<2000> vis[2000];

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  return b ? gcd(b, a % b) : a;
}

struct Node {
  int x, y, t;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  freopen("data.in", "r", stdin);
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  cin >> x >> y;
  x--, y--;
  q.push({x, y, 0});
  vis[x][y] = true;
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (a[x][y] == 1) {
      cout << t;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy]) continue;
      a[xx][yy] = gcd(a[x][y], a[xx][yy]);
      q.push({xx, yy, t + 1});
      vis[xx][yy] = true;
    }
  }
  cout << -1;
  return 0;
}