#include <bits/stdc++.h>
#define double long double

int a[101];
double f[101][101][101];

const double pi = acos(-1);

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Sq(int i, int j) {
  double d = (a[j] - a[i]) * pi / 180;
  double s = std::abs(sin(d) * 1000 * 1000 / 2);
  // std::cout << s << '\n';
  return s;
}

signed main() {
  freopen("C.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  double ans = 0;
  for (int S = 0; S < (1 << n); S++) {
    int cnt = __builtin_popcountll(S);
    double cur = 0;
    if (cnt < 3 || cnt != m) continue;
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
      if (S >> i & 1) {
        v.push_back(i);
      }
    }
    for (int i = 1; i < v.size(); i++) {
      cur += Sq(v[i], v[i - 1]);
    }
    cur += Sq(v.front(), v.back());
    ans = std::max(ans, cur);
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
  return 0;
}