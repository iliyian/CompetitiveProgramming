// date: 2024-05-14 17:19:34
// tag: 三分
// 可能是精度不够，或者又是三分的等于号出问题了

#include <bits/stdc++.h>
#include <iomanip>
#define int long long
#define eps (1e-7)
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n + 1), t(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  auto check = [&](double mid) {
    double ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, t[i] + abs(x[i] - mid));
    }
    return ans;
  };
  double l = 0, r = (int)1e8;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    double lmid = mid - eps, rmid = mid + eps;
    if (check(lmid) < check(rmid)) r = mid;
    else l = mid;
  }
  cout << setprecision(20) << (check(l) < check(r) ? l : r) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}