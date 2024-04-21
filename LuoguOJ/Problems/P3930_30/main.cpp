#include <bits/stdc++.h>
#define Arr array<array<char, 60>, 60>
using namespace std;

struct Node {
  int x, y, t;
  Arr a;
};
bitset<60> attack[60];
bitset<60> vis[60];

int n, sx, sy;

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dxx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyy[] = {1, 2, 2, 1, -1, -2, -2, -1};

inline bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

void loop(Arr &a, int x, int y, int s, int t, int xd[], int yd[]) {
  for (int k = s; k < t; k++) {
    int xx = x + xd[k], yy = y + yd[k];
    if (in(xx, yy))
      attack[xx][yy] = true;
  }
}

void loopendless(Arr &a, int x, int y, int s, int t, int xd[], int yd[]) {
  for (int k = s; k < t; k++)
    for (int l = 1;; l++) {
      int xx = x + xd[k] * l, yy = y + yd[k] * l;
      if (in(xx, yy)) {
        attack[xx][yy] = true;
        if (a[xx][yy] != '.') break;
      }
      else break;
    }
}

void refresh(Arr &a) {
  for (int i = 0; i < n; i++)
    attack[i].reset();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      switch (a[i][j]) {
        case 'X':
          loop(a, i, j, 0, 8, dx, dy);
        break;
        case 'Q':
          loopendless(a, i, j, 0, 8, dx, dy);
        break;
        case 'B':
          loopendless(a, i, j, 4, 8, dx, dy);
        break;
        case 'C':
          loopendless(a, i, j, 0, 4, dx, dy);
        break;
        case 'P':
          loop(a, i, j, 5, 7, dx, dy);
        break;
        case 'K':
          loop(a, i, j, 0, 8, dxx, dyy);
        break;
        default:
        break;
      }
}

array<array<int, 60>, 60> step;
Arr ori;
void solve() {
  for (int i = 0; i < n; i++)
    step[i].fill(0x3f3f3f3f);
  queue<Node> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> ori[i][j];
      if (ori[i][j] == 'O')
        sx = i, sy = j;
    }
  q.push({sx, sy, 0, ori});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    Arr &a = node.a;
    if (a[x][y] == 'X') {
      cout << t << '\n';
      return;
    }
    if (vis[x][y]) continue;
    vis[x][y] = true;
    a[x][y] = '.';
    refresh(a);
    for (int i = 0; i < 8; i++) {
      int xx = x + dxx[i], yy = y + dyy[i];
      if (in(xx, yy))
        q.push({xx, yy, t + 1, a});
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  while (cin >> n) solve();
  return 0;
}