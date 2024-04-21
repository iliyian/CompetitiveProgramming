#include <bits/stdc++.h>
#define mod 19650827
using namespace std;

int a[1001], f[1001][1001][2];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++)
    f[i][i][0] = 1;
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      // 三维状态表示
      if (a[i] < a[i + 1]) f[i][j][0] += f[i + 1][j][0];
      if (a[i] < a[j]) f[i][j][0] += f[i + 1][j][1];
      if (a[j] > a[j - 1]) f[i][j][1] += f[i][j - 1][1];
      if (a[j] > a[i]) f[i][j][1] += f[i][j - 1][0];
      f[i][j][0] %= mod;
      f[i][j][1] %= mod;
    }
  }
  cout << (f[1][n][0] + f[1][n][1]) % mod;
  return 0;
}