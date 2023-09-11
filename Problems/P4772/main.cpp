#include <bits/stdc++.h>
using namespace std;

char a[300][300];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

struct Node {
  int x, y, t;
  string s;
  array<bitset<300>, 300> vis;
  bool operator < (const Node &b) const {
    if (t == b.t) return s.size() < b.s.size();
    return t > b.t;
  }
};
priority_queue<Node> q;



int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int R, C, N, sx, sy;
  cin >> R >> C >> N;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A') sx = i, sy = j;
    }
  q.push({sx, sy, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    string &s = node.s;
    if (node.vis[x][y]) continue;
    node.vis[x][y] = true;
    if (isalpha(a[x][y])) {
      s.push_back(a[x][y]);
    }
    if (s.size() == N) {
      cout << t << '\n' << node.s;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= R || yy < 0 || yy >= C || a[xx][yy] == '*') continue;
      q.push({xx, yy, t + 1, s, node.vis});
    }
  }
  return 0;
}