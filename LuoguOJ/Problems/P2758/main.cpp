#include <bits/stdc++.h>
using namespace std;

int f[2003][2003];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  string a, b;
  cin >> a >> b;
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= a.size(); i++)
    f[i][0] = i;
  for (int i = 1; i <= b.size(); i++)
    f[0][i] = i;
  for (int i = 1; i <= a.size(); i++)
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1])
        f[i][j] = f[i - 1][j - 1];
      else
        f[i][j] = min(min(f[i - 1][j], f[i][j - 1]),
          f[i - 1][j - 1]) + 1;
    }
  cout << f[a.size()][b.size()];
  return 0;
}