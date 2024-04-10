// date: 2024-04-09 15:13:09
// tag: map浮点键精度问题

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<double> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  auto get = [&](int i, int j) {
    double x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
    double a = (y1 * x2 - y2 * x1) / (x1 - x2) / x1 / x2;
    double b = (y2 * x1 * x1 - y1 * x2 * x2) / (x1 - x2) / x1 / x2;
    return a < 0 ? pair{round(a * 1000000000) / 1000000000, round(b * 1000000000) / 1000000000} : pair{0.0, 0.0};
    // return a < 0 && b > 0? pair{a, b} : pair{0.0, 0.0};
  };
  auto lowbit = [&](int x) {
    return x & -x;
  };
  vector<int> f(1 << n, INT_MAX);

  map<pair<double, double>, int> dots;
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    f[1 << i] = 1;
    for (int j = 0; j < i; j++) {
      if (x[i] == x[j]) continue;
      auto [a, b] = get(i, j);
      if (a == 0) continue;
      auto &x = dots[{a, b}];
      int y = (1 << i) | (1 << j);
      x |= y;
      f[x] = 1;
    }
  }
  for (int S = 0; S < 1 << n; S++) {
    int x = __lg(lowbit(~S));
    for (int i = 0; i < n; i++) {
      f[S | (1 << i)] = min(f[S | (1 << i)], f[S] + 1);
      if (i == x) continue;
      int y = dots[get(i, x)];
      f[S | dots[get(i, x)]] = min(f[S | dots[get(i, x)]], f[S] + 1);
    }
  }
  cout << f[(1 << n) - 1] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}