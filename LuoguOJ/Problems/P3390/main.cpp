// date: 2024-03-08 11:10:53
// tag: 矩阵快速幂，单位矩阵

#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

struct Mat {
  int n, m;
  Mat(int n, int m) {
    this->n = n, this->m = m;
    a.assign(n + 1, vector<int>(m + 1));
  }
  vector<vector<int>> a;
  Mat operator * (const Mat &b) {
    Mat c(n, b.m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= b.m; j++) {
        for (int k = 1; k <= m; k++) {
          c.a[i][j] += a[i][k] * b.a[k][j] % mod;
          c.a[i][j] %= mod;
        }
      }
    }
    return c;
  }
  Mat& operator *= (const Mat &b) {
    return *this = (*this) * b;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  Mat a(n, n), ans(n, n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a.a[i][j];
    }
    ans.a[i][i] = 1;
  }
  while (k) {
    if (k & 1) ans *= a;
    a *= a;
    k >>= 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans.a[i][j] << " \n"[j == n];
    }
  }

  return 0;
}