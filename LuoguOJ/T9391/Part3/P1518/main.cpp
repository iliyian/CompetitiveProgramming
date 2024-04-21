#include <bits/stdc++.h>
using namespace std;

char m[10][10];
int fx, fy, fd = 0;
int cx, cy, cd = 0;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void move(int &x, int &y, int &d) {
  int x1 = x + dx[d], y1 = y + dy[d];
  if (x1 < 0 || x1 >= 10 || y1 < 0 || y1 >= 10 || m[x1][y1] == '*') d++;
  else x = x1, y = y1;
  if (d >= 4) d = 0;
}

int main() {
  freopen("data.in", "r", stdin);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> m[i][j];
      if (m[i][j] == 'C') cx = i, cy = j; 
      if (m[i][j] == 'F') fx = i, fy = j;
    }
  }
  int ans = 0;
  while (fx != cx || fy != cy) {
    if (ans >= 1000000) break;
    move(fx, fy, fd);
    move(cx, cy, cd);
    ans++;
  }
  cout << (ans == 1000000 ? 0 : ans);
  return 0;
}