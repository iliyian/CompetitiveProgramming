#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

struct Mat {
  int a[3][3];
  Mat() {
    memset(a, 0, sizeof(a));
  }
  Mat operator * (const Mat &b) {
    Mat res;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++) {
          res.a[i][j] += a[i][k] * b.a[k][j];
          res.a[i][j] %= mod;
        }

    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  Mat base, ans;
  for (int i = 0; i < 3; i++)
    ans.a[i][i] = 1;
  base.a[0][0] = base.a[0][2] = base.a[1][0] = base.a[2][1] = 1;
  if (n <= 3) {
    cout << 1 << '\n';
    return;
  }

  while (n) {
    if (n & 1) ans = ans * base;
    base = base * base;
    n >>= 1;
  }

  cout << ans.a[1][0] << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}