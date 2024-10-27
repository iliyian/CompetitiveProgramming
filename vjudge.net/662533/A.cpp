#include <bits/stdc++.h>
#define int long long

constexpr double eps = 1e-4;
constexpr int N = 5e5;

double x[N + 1];
int w[N + 1], n;

double check(double mid) {
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += std::pow(std::abs(x[i] - mid), 3) * w[i];
  }
  return ans;
};

void solve() {
  std::cin >> n;
  double l = INT_MAX, r = INT_MIN;
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> w[i];
    l = std::min(l, x[i]);
    r = std::max(r, x[i]);
  }
  while (l < r - eps * 2) {
    double mid = (l + r) / 2;
    double lmid = mid - eps, rmid = mid + eps;
    if (check(lmid) < check(rmid)) r = rmid;
    else l = lmid;
  }
  std::cout << (int)std::round(check(l)) << '\n';
}

signed main() {
  freopen("A.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  for (int i = 1; i <= t; i++) {
    std::cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}