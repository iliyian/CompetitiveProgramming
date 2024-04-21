#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
array<array<int, 400>, 400> step{};

int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1}, dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main() {
  ios::sync_with_stdio(false);

  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--, y--;
  q.push(make_pair(x, y));
  step[x][y] = 0;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int x0 = p.first + dx[i], y0 = p.second + dy[i];
      if (x0 >= 0 && x0 < n && y0 >= 0 && y0 < m && !step[x0][y0]) {
        q.push(make_pair(x0, y0));
        step[x0][y0] = step[p.first][p.second] + 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == x && j == y) cout << 0;
      else if (step[i][j]) cout << step[i][j];
      else cout << -1;
      cout << " ";
    }
    cout << endl;
  }
  return 0;
}