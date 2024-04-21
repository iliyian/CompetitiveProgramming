#include <bits/stdc++.h>
#define N 105
using namespace std;

int a[N][N], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bitset<N> vis[N];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (!a[i][j]) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
          int xx = i + dx[k], yy = j + dy[k];
          if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
          vis[xx][yy] = true;
        }
      }
    }
  int ans = n * m;
  for (int i = 0; i < n; i++)
    ans -= vis[i].count();
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("6.in", "r", stdin);
  freopen("6.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}