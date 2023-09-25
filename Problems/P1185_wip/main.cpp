#include <bits/stdc++.h>
using namespace std;

int len[11];
char a[1000][1000];

void dfs(int n, int x, int y) {
  int rx = x, ry = y;
  if (!n) return;
  for (int i = 0; i < len[n]; i++)
    a[x][y] = ' ', y++;
  a[x][y] = 'o';
  for (int i = 0; i < len[n]; i++)
    ++y, a[x][y] = ' ';
  x++, y = ry;
  for (int i = 0; i < len[n - 1]; i++, x++) {
    for (int j = 0; j < len[n] * 2 + 1; j++, y++) {
      if (j == len[n] - i) a[x][y] = '/';
      else if (j == len[n] + i) a[x][y] = '\\';
      else a[x][y] = ' ';
    }
    y = ry;
  }
  dfs(n - 1, x, ry);
  dfs(n - 1, x, ry + len[n]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  len[0] = 1;
  len[1] = 2;
  len[2] = 2;
  for (int i = 3; i <= n; i++)
    len[i] = 2 * len[i - 1] + 1;
  dfs(n, 0, 0);
  for (int i = 0; i < len[n] + 1; i++) {
    for (int j = 0; j < 2 * len[n] + 1; j++)
      cout << char(a[i][j]);
    cout << '\n';
  }
  return 0;
}