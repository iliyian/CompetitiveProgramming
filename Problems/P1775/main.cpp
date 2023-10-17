#include <bits/stdc++.h>
#define N 301
using namespace std;

int a[N], sum[N], f[N][N];

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  sum[0] = 0;
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    f[i][i] = 0;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++)
        // [i, k], [k + 1, j]
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
    }
  }
  cout << f[1][n];
  return 0;
}