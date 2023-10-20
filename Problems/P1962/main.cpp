#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

struct Mat {
  int a[2][2];
  Mat() {
    memset(a, 0, sizeof(a));
  }
  Mat operator * (const Mat &b) {
    Mat res;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) {
          res.a[i][j] += a[i][k] * b.a[k][j] % mod;
          res.a[i][j] %= mod;
        }
    return res;
  }
};

signed main() {
  int n;
  cin >> n;
  if (n <= 2) {
    cout << 1;
    return 0;
  }

  Mat base, ans;
  base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
  ans.a[0][0] = ans.a[0][1] = 1;
  n--;
  while (n) {
    if (n & 1) ans = ans * base;
    base = base * base;
    n >>= 1;
  };
  cout << ans.a[0][1] % mod;
  return 0;
}