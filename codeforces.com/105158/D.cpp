// date: 2024-05-15 21:16:58
// tag: 计算几何

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n + 1), y(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    id[i] = i;
  }
  sort(id.begin() + 1, id.end(), [&](const int &a, const int &b) {
    return x[a] - y[a] < x[b] - y[b];
  });
  auto calc = [&](int a, int b) {
    return (abs(x[a] - x[b]) + abs(y[a] - y[b])) / sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
  };
  double ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    ans = max(ans, calc(id[i], id[i + 1]));
  }
  sort(id.begin() + 1, id.end(), [&](const int &a, const int &b) {
    return x[a] + y[a] < x[b] + y[b];
  });
  for (int i = 1; i <= n - 1; i++) {
    ans = max(ans, calc(id[i], id[i + 1]));
  }
  cout << fixed << setprecision(20) << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}