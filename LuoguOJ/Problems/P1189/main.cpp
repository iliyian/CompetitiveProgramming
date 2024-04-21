// 这题和P1126一样，vis则break

#include <bits/stdc++.h>
using namespace std;

bitset<51> a[51], ans[51];
bitset<1000> vis[51][51];

struct Node {
  int x, y, t;
};
queue<Node> q;

map<string, int> s2i = {
  {"NORTH", 0},
  {"EAST", 1},
  {"SOUTH", 2},
  {"WEST", 3},
};
int dirs[1000];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  freopen("data.in", "r", stdin);
  int r, c, sx, sy, N;
  cin >> r >> c;

  char ch;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> ch;
      if (ch == '*') sx = i, sy = j;
      else if (ch == 'X') a[i][j] = true;
    }
    cin.get();
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    dirs[i] = s2i[str];
  } 

  q.push({sx, sy, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (t == N) {
      ans[x][y] = true;     
      continue;
    }
    if (vis[x][y][t]) continue;
    vis[x][y][t] = true;
    int d = dirs[t];
    for (int i = 1;; i++) {
      int xx = x + dx[d] * i, yy = y + dy[d] * i;
      if (xx < 0 || xx >= r || yy < 0 || yy >= c || a[xx][yy] || vis[xx][yy][t + 1]) break;
      q.push({xx, yy, t + 1});
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (ans[i][j]) cout << '*';
      else if (a[i][j]) cout << 'X';
      else cout << '.';
    }
    cout << '\n';
  }
  return 0;
}