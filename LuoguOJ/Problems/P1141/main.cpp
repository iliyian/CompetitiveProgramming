#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> q;
bitset<1000> a[1000], vis[1000];
int color[1000][1000], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m, ans[100001];

void solve(int x, int y, int clr) {
  if (color[x][y]) return;
  color[x][y] = clr;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx >= 0 && xx < n && yy >= 0 && yy < n && a[xx][yy] == !a[x][y]) {
      solve(xx, yy, clr);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  memset(ans, 0, sizeof(ans));
  q.resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      a[i][j] = c == '1';
      color[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    q.push_back(make_pair(x, y));
    solve(x, y, i + 1);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans[color[i][j]]++;
  for (int i = 0; i < q.size(); i++)
    cout << ans[color[q[i].first][q[i].second]] << '\n';
  return 0;
}