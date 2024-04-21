#include <bits/stdc++.h>
using namespace std;

int f[201][201];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  string str;
  cin >> str;
  memset(f, 0x3f, sizeof(f));

  str = '#' + str;

  int n = str.size() - 1;
  for (int i = 1; i <= n; i++) {
    f[i][i] = 1;
  }

  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      if (str[i] == str[j]) {
        f[i][j] = min(f[i + 1][j], f[i][j - 1]);
      } else for (int k = i; k < j; k++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
      }
    }
  }

  cout << f[1][n];
  return 0;
}