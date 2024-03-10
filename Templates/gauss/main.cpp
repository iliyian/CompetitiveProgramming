// date: 2024-03-05 14:47:17
// tag: 高斯消元法
// wa#0102没有考虑浮点运算精度，极小值可以视为零
// 3: debug没删

#include <bits/stdc++.h>
#define eps 1e-10
#define int long long
using namespace std;

bool eq(double x, double y) {
  if (abs(x - y) < eps) {
    return true;
  }
  return false;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<long double>> a(n + 1, vector<long double>(n + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n + 1; j++) {
      cin >> a[i][j];
    }
  }
  
  int r = 1;
  for (int i = 1; i <= n; i++) {
    // 确实需要换个顺序
    int t = r;
    for (int j = r + 1; j <= n; j++) {
      if (abs(a[j][i]) > abs(a[t][i])) {
        t = j;
      }
    }
    if (eq(a[t][i], 0)) {
      continue;
    }
    swap(a[t], a[r]);

    // 系数化1便于回代
    for (int j = r + 1; j <= n + 1; j++) {
      a[r][j] /= a[r][i];
    }
    a[r][i] /= a[r][i];
    for (int j = 1; j <= n; j++) {
      if (j == r) {
        continue;
      }
      double t = a[j][i];
      // 注意是r，回代连着的一系列项
      for (int k = r; k <= n + 1; k++) {
        a[j][k] -= t * a[r][k];
      }
    }
    r++;
    // swap(a[t], a[i]);
  }

  for (int i = n; i >= 1; i--) {
    for (int j = i - 1; j >= 1; j--) {
      // 只考虑最后的值
      a[j][n + 1] -= a[j][i] * a[i][n + 1];
    }
  }
  bool f = false;
  if (r <= n) {
    for (int i = r; i <= n; i++) {
      if (!eq(a[i][n + 1], 0)) {
        cout << -1 << '\n';
        return 0;
      }
    }
    cout << 0 << '\n';
    return 0;
  }
  
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n + 1; j++) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // cout << z << '\n';
  for (int i = 1; i <= n; i++) {
    cout << "x" << i << '=' << fixed << setprecision(2)
      << a[i][n + 1] << '\n';
  }

  return 0;
}