// 可能一颗炸弹全都炸了

#include <bits/stdc++.h>
using namespace std;

int a[5010][5010];

int main( ){
  freopen("data.in", "r", stdin);
  int n, m, mx = -1, my = -1;
  cin >> n >> m;
  for (int i = 0; i < 5010; i++)
    for (int j = 0; j < 5010; j++)
      a[i][j] = 0;
  for (int i = 0; i < n; i++) {
    int x, y, v;
    cin >> x >> y >> v; x++, y++;
    a[x][y] += v;
    mx = max(mx, x), my = max(my, y);
  }
  mx = max(mx, m), my = max(my, m);
  for (int i = 1; i <= mx; i++) {
    for (int j = 1; j <= my; j++) {
      a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
    }
  }
  int ans = -1;
  for (int i = m; i <= mx; i++) {
    for (int j = m; j <= my; j++) {
      ans = max(ans, a[i][j] - a[i-m][j] - a[i][j-m] + a[i-m][j-m]);
    }
  }
  cout << ans;
  return 0;
}