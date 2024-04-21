#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 2333;

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
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  Mat base, ans;
  cin >> base.a[0][0] >> base.a[1][0] >> ans.a[0][1] >> ans.a[0][0] >> n >> mod;
  base.a[0][1] = 1;
  // mod = 998244353;

  if (n <= 2) {
    cout << ans.a[0][n] % mod;
    return 0;
  }

  n -= 2;
  while (n) {
    if (n & 1) ans = ans * base;
    base = base * base;
    n >>= 1;
  }

  cout << ans.a[0][0] % mod;
  return 0;
}