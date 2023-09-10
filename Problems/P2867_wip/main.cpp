#include <bits/stdc++.h>
using namespace std;

char a[100][100];
vector<pair<int, int>> v;

int handle(int i, int j, int x, int y) {
  if (x < 0 || x >= n && y < 0 || y >= n) return 0;

}

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'J')
        v.push_back({i, j});
    }
  int ans = 0;
  for (int i = 0; i < v.size(); i++)
    for (int j = i + 1; j < v.size(); j++) {
      int dx = v[j].second - v[i].second, dy = v[i].first - v[j].first;

      int x1 = v[i].first + dx, y1 = v[i].second + dy;
      int x2 = v[j].first + dx, y2 = v[j].second + dy;
      int x3 = v[i].first - dx, y3 = v[i].second - dy;
      int x4 = v[j].first - dx, y4 = v[j].second - dy;

      if 
    (
      ((x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && 
      x2 >= 0 && x2 < n && y2 >= 0 && y2 < n &&
      a[x1][y1] != 'B' && a[x2][y2] != 'B')
      || 
      (x3 >= 0 && x3 < n && y3 >= 0 && y3 < n && 
      x4 >= 0 && x4 < n && y4 >= 0 && y4 < n &&
      a[x3][y3] != 'B' && a[x4][y4] != 'B'))
    )
      ans = max(ans, 
        (v[i].first - v[j].first) * (v[i].first - v[j].first) +
        (v[i].second - v[j].second) * (v[i].second - v[j].second)
      );
    }
  cout << ans;
  return 0;
}