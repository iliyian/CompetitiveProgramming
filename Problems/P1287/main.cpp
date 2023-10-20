#include <bits/stdc++.h>
using namespace std;

int f[11][11];

int main() {
  int n, r;
  cin >> n >> r;

  memset(f, 0, sizeof(f));
  for (int i = 1; i <= 10; i++)
    f[i][i] = 1;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= r; j++)
      if (j != i)
        f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j];

  for (int i = 2; i <= r; i++)
    f[n][r] *= i;
  cout << f[n][r];
  return 0;
}