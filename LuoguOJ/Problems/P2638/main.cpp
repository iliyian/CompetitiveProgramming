// #11卡ull, #subtask1 卡 __int128 就离谱

#include <bits/stdc++.h>
using namespace std;

__int128_t f[55][55];

void print(__int128_t n) {
  if (n >= 10) print(n / 10);
  n %= 10;
  cout << char(n + '0');
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i <= 50; i++) {
    f[i][0] = f[i][i] = 1;
    for (int j = 1; j < i; j++)
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
  }

  __int128_t ans = 0;
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
      ans += f[i + n - 1][n - 1] * f[j + n - 1][n - 1];

  print(ans);
  return 0;
}