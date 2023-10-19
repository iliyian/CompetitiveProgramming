// 树原来就是线段啊

#include <bits/stdc++.h>
using namespace std;

int a[30], f[30][30], root[30][30], n;

void print(int l, int r) {
  if (!root[l][r]) return;
  cout << root[l][r] << ' ';
  if (l > r) return;
  print(l, root[l][r] - 1);
  print(root[l][r] + 1, r);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n;
  memset(f, -0x3f, sizeof(f));
  memset(root, 0, sizeof(root));
  for (int i = 1; i <= n; i++) {
    cin >> f[i][i];
    for (int j = i; j <= n; j++)
      root[i][j] = i;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;

      f[i][j] = f[i][i] + f[i + 1][j]; // 边界条件
      for (int k = i + 1; k < j; k++) {
        int t = f[i][k - 1] * f[k + 1][j] + f[k][k];
        if (f[i][j] <= t) {
          f[i][j] = t;
          root[i][j] = k;
        }
      }
    }
  }
  cout << f[1][n] << '\n';
  print(1, n);
  return 0;
}