#include <bits/stdc++.h>

double a[101];

const double pi = acos(-1);

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double S(int i, int j, int k) {
  double ri = (double)a[i] / 360 * 2 * pi;
  double xi = cos(ri) * 1000, yi = sin(ri) * 1000;
  double rj = (double)a[j] / 360 * 2 * pi;
  double xj = cos(rj) * 1000, yj = sin(rj) * 1000;
  double rk = (double)a[k] / 360 * 2 * pi;
  double xk = cos(rk) * 1000, yk = sin(rk) * 1000;
  double I = dis(xj, yj, xk, yk), J = dis(xi, yi, xk, yk), K = dis(xi, yi, xj, yj);

  // std::cout << xi << ' ' << yi << ' ' << xj << ' ' << yj << ' ' << xk << ' ' << yk << '\n';

  double s = 0.25 * sqrt((I + J + K) * (I + J - K) * (J + K - I) * (I + K - J));
  return s;
}

signed main() {
  freopen("C.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector f(n + 1, std::vector<std::vector<double>>(n + 1, std::vector<double>(m + 1, 0)));
  for (int k = 3; k <= m; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 2; j <= n; j++) {
        for (int t = i + 1; t <= j - 1; t++) {
          f[i][j][k] = std::max(f[i][j][k], f[i][t][k - 1] + S(i, t, j));
        }
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 2; j <= n; j++) {
      for (int k = 3; k <= std::min(m, j - i + 1); k++) {
        ans = std::max(ans, f[i][j][k]);
      }
    }
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
  return 0;
}