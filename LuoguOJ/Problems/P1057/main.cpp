#include <bits/stdc++.h>
using namespace std;

int a[31][31];

int main() {
  int n, m;
  cin >> n >> m;
  a[0][1] = 1;
  for (int i = 1; i <= m; i++) {
    a[i][1] = a[i - 1][n] + a[i - 1][2];
    a[i][n] = a[i - 1][n - 1] + a[i - 1][1];
    for (int j = 2; j <= n - 1; j++)
      a[i][j] = a[i - 1][j - 1] + a[i - 1][j + 1];
  }
  cout << a[m][1];
  return 0;
}