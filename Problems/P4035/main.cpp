// date: 2024-03-08 13:18:01
// tag: 没看题解哦
// 高斯消元

#include <bits/stdc++.h>
#define eps 1e-10
using namespace std;

bool eq(double x, double y) {
  return abs(x - y) < eps;
}

void gauss(vector<vector<double>> &a, int n) {
  int r = 1;
  for (int c = 1; c <= n; c++) {
    int t = r;
    for (int i = r + 1; i <= n; i++) {
      if (abs(a[i][c]) > abs(a[t][c])) {
        t = i;
      }
    }
    if (eq(a[t][c], 0)) {
      continue;
    }
    swap(a[t], a[r]);
    for (int i = r + 1; i <= n + 1; i++) {
      a[r][i] /= a[r][c];
    }
    a[r][c] /= a[r][c];
    for (int i = 1; i <= n; i++) {
      if (i != r) {
        double t = a[i][c];
        for (int j = r; j <= n + 1; j++) {
          a[i][j] -= t * a[r][j];
        }
      }
    }
    r++;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = i - 1; j >= 1; j--) {
      a[j][n + 1] -= a[i][j] * a[j][n + 1];
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector a(n + 2, vector<double>(n + 1));
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  vector g(n + 1, vector<double>(n + 2));
  for (int i = 2; i <= n + 1; i++) {
    double c = 0;
    for (int j = 1; j <= n; j++) {
      g[i - 1][j] = 2 * (a[i][j] - a[1][j]);
      c += a[i][j] * a[i][j] - a[1][j] * a[1][j];
    }
    g[i - 1][n + 1] = c;
  }
  gauss(g, n);
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(3) << g[i][n + 1] << ' ';
  }

  return 0;
}