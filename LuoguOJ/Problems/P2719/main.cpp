#include <bits/stdc++.h>
using namespace std;

double f[1251][1251];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  n >>= 1;
  memset(f, 0, sizeof(f));
  for (int i = 2; i <= n; i++)
    f[i][0] = f[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      f[i][j] = (f[i - 1][j] + f[i][j - 1]) * 0.5;
  }
  cout << fixed << setprecision(4) << f[n][n];
  return 0;
}