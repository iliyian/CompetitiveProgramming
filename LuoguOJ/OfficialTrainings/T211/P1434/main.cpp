// 平地滑导致segmantation fault

#include <bits/stdc++.h>
using namespace std;

int a[101][101], r, c, ans = -1, mem[101][101];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int find(int x, int y) {
  if (mem[x][y] != -1) return mem[x][y];
  int dfst = 0;
  for (int i = 0; i < 4; i++) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (x0 < 0 || x0 >= r || y0 < 0 || y0 >= c || a[x0][y0] >= a[x][y]) continue;
    dfst = max(dfst, find(x0, y0));
  }
  mem[x][y] = 1 + dfst;
  ans = max(ans, mem[x][y]);
  return mem[x][y];
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      mem[i][j] = -1;
    }
  }
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      find(i, j);
  cout << ans;
  return 0;
}