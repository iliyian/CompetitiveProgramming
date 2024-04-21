#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int arow[N], acol[N], n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int a[N];

int change(int x, int y) {
  return (x - 1) * m + y;
}

int main() {
  freopen("J.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      if (x == 1) {
        arow[y] = i;
      } else {
        acol[y] = i;
      }
    } else {
      a[change(x, y)] = i;
      for (int j = 0; j < 4; j++) {
        int xx = x + dx[j], yy = y + dy[j];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
        a[change(xx, yy)] = i;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int idx = change(i, j);
      if (arow[i] < a[idx] && acol[j] < a[idx])
        ans++;
    }
  cout << ans;
  return 0;
}