#include <bits/stdc++.h>
using namespace std;

char a[25][25];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("H.in", "r", stdin);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x, y, cnt = 0;
    cin >> x >> y;
    // x--, y--;
    if (a[x][y] == '1' || a[x][y] == '#') cnt++, a[x][y] = '0';
    for (int j = 0; j < 4; j++) {
      int xx = dx[j] + x, yy = dy[j] + y;
      if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
      if (a[xx][yy] == '#') a[xx][yy] = '1';
      else if (a[xx][yy] == '1') a[xx][yy] = '0', cnt++;
    }
    cout << cnt << '\n';
  }
}