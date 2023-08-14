#include <bits/stdc++.h>
using namespace std;

bitset<1000> a[1000], b[1000];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, ans = 0, r, c;

void dfs(int x, int y) {
  if (x < 0 || x >= r || y < 0 || y >= c) return;
  if (a[x][y]) {
    a[x][y] = false;
    for (int i = 0; i < 4; i++)
      dfs(x + dx[i], y + dy[i]);
  }
}

int main() {
  char ch;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> ch;
      a[i][j] = ch == '#';
    }
  }
  for (int i = 0; i < r - 1; i++) {
    for (int j = 0; j < c - 1; j++) {
      int cnt = 0;
      cnt += a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
      if (cnt == 3) {
        cout << "Bad placement.";
        return 0;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j])
        ans++, dfs(i, j);
    }
  }
  cout << "There are " << ans << " ships.";
  return 0;
}