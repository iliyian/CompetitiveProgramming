#include <bits/stdc++.h>
using namespace std;

int a[501], f[501][501];

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < n; i++) {
    f[i][i] = 1;
    if (i != n - 1)
      f[i][i + 1] = 1 + (a[i] != a[i + 1]);
  }
  for (int len = 3; len <= n; len++) {
    // 2 has no k
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      if (a[i] == a[j])
        f[i][j] = f[i + 1][j - 1];
      for (int k = i; k < j; k++)
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
    }
  }
  cout << f[0][n - 1];
  return 0;
}