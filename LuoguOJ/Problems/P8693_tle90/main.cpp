#include <bits/stdc++.h>
using namespace std;

char a[300][300];
int sum[300][300];

struct Node {
  int x, y, t, sz;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
      sum[i][j] = a[i][j] == '*';
      if (i) sum[i][j] += sum[i - 1][j];
      if (j) sum[i][j] += sum[i][j - 1];
      if (i && j) sum[i][j] -= sum[i - 1][j - 1];
    }

  bitset<300> vis[300];
  q.push({2, 2, 0, 2});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t, sz = node.sz;
    if (x == N - 3 && y == N - 3) {
      cout << t;
      return 0;
    }
    if (t == K) sz = 1;
    if (t == 2 * K) sz = 0;
    if (sz) {
      q.push({x, y, t + 1, sz});
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      bool f = true;
      if (xx - sz < 0 || xx + sz >= N || yy - sz < 0 || yy + sz >= N) continue;
      int s = sum[xx + sz][yy + sz];
      if (xx - sz) s -= sum[xx - sz][yy + sz];
      if (yy - sz) s -= sum[xx + sz][yy - sz];
      if (xx - sz && yy - sz) s += sum[xx - sz][yy - sz];
      if (s) continue;
      if (vis[x][y]) continue;
      vis[x][y] = true;
      q.push({xx, yy, t + 1, sz});
    }
  }
  return 0;
}