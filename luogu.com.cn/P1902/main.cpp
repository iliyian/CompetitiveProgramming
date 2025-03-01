// 二分或者-O2

#include <bits/stdc++.h>
using namespace std;

int a[1000][1000], n, m;
bitset<1000> vis[1000];

struct Node {
  int x, y, maxn;
  bool operator < (const Node &b) const {
    if (maxn == b.maxn) return x < b.x;
    return maxn > b.maxn;
  }
};
priority_queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int sx, int sy) {
  q.push({sx, sy, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int x = node.x, y = node.y;
    if (x == n - 1) {
      cout << node.maxn;
      exit(0);
    }
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m)
        continue;
      q.push({xx, yy, max(node.maxn, a[xx][yy])});
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  bfs(0, 0);
  return 0;
}