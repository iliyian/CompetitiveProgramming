#include <bits/stdc++.h>
#define int long long
using namespace std;

int h[15], w[15], n, m;
char a[2000][2000];
bitset<5000> del;

void display() {
  for (int i = 0; i < h[n + 1]; i++) {
    for (int j = 0; j < 2 * h[n + 1] - 1; j++)
      cout << (a[i][j] ? a[i][j] : ' ');
    cout << '\n';
  }
}

void dfs(int x, int y, int n, int p) {
  if (!n || del[p]) return;
  int l = p << 1, r = p << 1 | 1;
  a[x][y] = 'o';
  for (int i = 0; i < h[n]; i++) {
    for (int j = 1; j <= h[n] - 1; j++)
      if (!del[l] && j == i)
        a[x + i][y - j] = '/';
    for (int j = 1; j <= h[n] - 1; j++)
      if (!del[r] && j == i)
        a[x + i][y + j] = '\\';
  }
  dfs(x + h[n], y - h[n], n - 1, l);
  dfs(x + h[n], y + h[n], n - 1, r);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  h[1] = 1, h[2] = 2;
  w[1] = 0, w[2] = 1;

  for (int i = 3; i <= n + 1; i++) {
    h[i] = 0;
    for (int j = 1; j < i; j++)
      h[i] += h[j];
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    del[(1 << x - 1) + y - 1] = true;
  }
  memset(a, 0, sizeof(a));

  dfs(0, h[n + 1] - 1, n, 1);

  display();

  return 0;
}