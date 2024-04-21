// #define int long long 太tmd必要了

#include <bits/stdc++.h>
using namespace std;

long long f[300010][2];

// void print(__int128_t x) {
//   if (x >= 10) print(x / 10);
//   cout << char(x % 10 + '0');
// }

int main() {
  freopen("A.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  long long x, y, z;
  cin >> x >> y >> z;
  char c;
  cin >> c;

  if (c == 'a') {
    f[0][0] = min(x, y + z * 2);
    f[0][1] = min(z + y, x + z);
  } else {
    f[0][0] = min(y, x + z * 2);
    f[0][1] = min(y + z, z + x);
  }
  // f[0][0] = min(c == 'A' ? y : x, z + (c == 'A' ? x : y));
  // f[0][1] = z + (c == 'A' ? x : y);

  int i = 1;
  while (cin >> c) {
    if (c == 'a') {
      f[i][0] = min(min(f[i - 1][0] + x, f[i - 1][0] + y + z * 2),
        f[i - 1][1] + z + min(x, y));
      f[i][1] = min(f[i - 1][0] + z + min(x, y),
        min(f[i - 1][1] + y, f[i - 1][1] + x + 2 * z));
    } else if (c == 'A') {
      f[i][0] = min(min(f[i - 1][0] + y, f[i - 1][0] + x + z * 2),
        f[i - 1][1] + z + min(x, y));
      f[i][1] = min(f[i - 1][0] + z + min(x, y),
        min(f[i - 1][1] + x, f[i - 1][1] + y + z * 2));
    }
    i++;
  }
  cout << min(f[i - 1][1], f[i - 1][0]);
  // print(min(f[i - 1][1], f[i - 1][0]));
  return 0;
}