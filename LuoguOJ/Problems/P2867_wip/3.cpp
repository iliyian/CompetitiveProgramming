#include <bits/stdc++.h>
using namespace std;

char a[100][100];

vector<pair<int, int>> v;

int dist2(int x, int y) {
  return (v[x].first - v[y].first) * (v[x].first - v[y].first) + 
    (v[x].second - v[y].second) * (v[x].second - v[y].second);
}

bool right(int i, int j, int k) {
  if (dist2(i, j) + dist2(j, k) != dist2(i, k)) return false;
  if (abs(v[i].first - v[j].first) != abs(v[j].second - v[k].second)) return false;
  if (abs(v[i].second - v[j].second) != abs(v[j].first - v[k].first)) return false;
  return true;
}

int n;

int handle(int i, int j, int k) {
  int cx2 = v[i].first + v[k].first, cy2 = v[i].second + v[k].second;
  int xx = cx2 - v[j].first, yy = cy2 - v[j].second;
  if (xx < 0 || xx >= n || yy < 0 || yy >= n || a[xx][yy] == 'B') return 0;
  return ((xx - v[j].first) * (xx - v[j].first) + (yy - v[j].second) * (yy - v[j].second)) / 2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'J')
        v.push_back({i, j});
    }
  int ans = 0;
  for (int i = 0; i < v.size(); i++)
    for (int j = i + 1; j < v.size(); j++)
      for (int k = j + 1; k < v.size(); k++) {
        if (right(i, j, k)) {
          ans = max(ans, handle(i, j, k));
        } else if (right(k, i, j)) {
          ans = max(ans, handle(k, i, j));
        } else if (right(i, k, j)) {
          ans = max(ans, handle(i, k, j));
        }
      }
  cout << ans;
  return 0;
}