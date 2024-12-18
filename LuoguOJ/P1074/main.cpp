#include <bits/stdc++.h>
using namespace std;

int w[9][9] = {
  {6, 6, 6, 6, 6, 6, 6, 6, 6},
  {6, 7, 7, 7, 7, 7, 7, 7, 6},
  {6, 7, 8, 8, 8, 8, 8, 7, 6},
  {6, 7, 8, 9, 9, 9, 8, 7, 6},
  {6, 7, 8, 9, 10, 9, 8, 7, 6},
  {6, 7, 8, 9, 9, 9, 8, 7, 6},
  {6, 7, 8, 8, 8, 8, 8, 7, 6},
  {6, 7, 7, 7, 7, 7, 7, 7, 6},
  {6, 6, 6, 6, 6, 6, 6, 6, 6},
};

int a[9][9], ans = -1;

bitset<10> row[9], col[9], sqr[3][3], vis[9];

struct Row {
  int zerocount = 0, r;
  bool operator < (const Row &b) const {
    return zerocount < b.zerocount;
  }
} rows[9];

void dfs(int x, int y, int sum, int cnt) {
  if (cnt == 81) {
    ans = max(ans, sum);
    return;
  }
  if (y == 9) {
    for (int i = 0; i < 9; i++)
      if (rows[i].r == x) {
        dfs(rows[i + 1].r, 0, sum, cnt);
        return;
      }
  }
  if (a[x][y]) {
    return dfs(x, y + 1, sum, cnt);
  }
  for (int i = 1; i <= 9; i++) {
    if (!row[x][i] && !col[y][i] && !sqr[x / 3][y / 3][i]) {
      row[x][i] = col[y][i] = sqr[x / 3][y / 3][i] = true;
      dfs(x, y + 1, sum + w[x][y] * i, cnt + 1);
      row[x][i] = col[y][i] = sqr[x / 3][y / 3][i] = false;
    }
  }
}

int main() {
  int sum = 0, cnt = 0;
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  for (int i = 0; i < 9; i++) {
    rows[i] = {0, i};
    for (int j = 0; j < 9; j++) {
      cin >> a[i][j];
      cnt += a[i][j] > 0;
      if (a[i][j]) {
        sum += a[i][j] * w[i][j];
        row[i][a[i][j]] = col[j][a[i][j]] = sqr[i / 3][j / 3][a[i][j]] = true;
      } else {
        rows[i].zerocount++;
      }
    }
  }
  sort(rows, rows + 9);
  dfs(rows[0].r, 0, sum, cnt);
  cout << ans;
  return 0;
}
