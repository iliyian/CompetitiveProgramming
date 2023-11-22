// date: 2023/11/21
// tag: 记忆化dfs
// wa#01: 由于使用0为数组边界，未初始化l,r为无穷，可能导致了错误
//        以及搞错回溯坐标位置

#include <bits/stdc++.h>
#define N 505
using namespace std;

int a[N][N], b[N], n, m, l[N][N], r[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bitset<N> vis[N];

void dfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
    if (a[xx][yy] < a[x][y]) {
      dfs(xx, yy);
      l[x][y] = min(l[x][y], l[xx][yy]);
      r[x][y] = max(r[x][y], r[xx][yy]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  memset(l, 0x3f, sizeof(l));
  memset(r, -0x3f, sizeof(r));
  for (int i = 0; i < m; i++)
    l[n - 1][i] = r[n - 1][i] = i;
  for (int i = 0; i < m; i++)
    if (!vis[0][i])
      dfs(0, i);
  int cnt = m - vis[n - 1].count();
  if (cnt) cout << 0 << '\n' << cnt;
  else {
    int L = 0, ans = 0;
    while (L < m) {
      int maxr = 0;
      for (int i = 0; i < m; i++)
        if (l[0][i] <= L)
          maxr = max(maxr, r[0][i]);
      ans++;
      L = maxr + 1;
    }
    cout << 1 << '\n' << ans;
  }
}