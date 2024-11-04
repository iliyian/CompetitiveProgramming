#include <bits/stdc++.h>
#include <random>
#define int long long

int a[101];
double f[101][101][101];

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

  double s = 0.25 * sqrt((I + J + K) * (I + J - K) * (J + K - I) * (I + K - J));
  return s;
}

std::mt19937 rd(std::random_device{}());

signed main() {
  freopen("C.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n = 25, m = 15;
  std::set<int> s;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    int x = rd() % 360;
    while (s.count(x)) {
      x = rd() % 360;
    }
    s.insert(x);
  }
  for (auto i : s) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  return 0;
}