// 特判太tmd的重要了

#include <bits/stdc++.h>
using namespace std;

bitset<101> a[101], vis[4][101];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int r, c, k, ans = 0;

bool check(int x, int y, int d) {
  for (int i = 1; i < k; i++) {
    int x0 = x + i * dx[d], y0 = y + i * dy[d];
    if (x0 < 0 || x0 >= r || y0 < 0 || y0 >= c || a[x0][y0]) return false;
  }
  return true;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> r >> c >> k;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char ch;
      cin >> ch;
      a[i][j] = ch == '#';
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j]) continue;
      if (k == 1) ans++;
      else for (int d = 0; d < 4; d++) {
        ans += check(i, j, d);
      }
    }
  }
  cout << (k == 1 ? ans : ans / 2);
  return 0;
}