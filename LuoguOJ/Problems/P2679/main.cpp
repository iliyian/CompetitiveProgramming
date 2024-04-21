#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[202][202], sumf[202][202];

signed main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  string a, b;
  cin >> a >> b;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      for (int l = k; l >= 1; l--) {
        sumf[j][l] = a[i - 1] == b[j - 1] ? sumf[j - 1][l] + f[j - 1][l - 1] : 0;
        f[j][l] += sumf[j][l];
        f[j][l] %= 1000000007;
      }
  cout << f[m][k];
  return 0;
}