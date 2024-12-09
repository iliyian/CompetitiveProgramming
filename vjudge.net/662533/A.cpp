#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

constexpr double eps = 1e-5;
constexpr int N = 5e5;

double x[N + 1], w[N + 1];
int n;

double check(double mid) {
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    double t = fabs(x[i] - mid);
    ans += t * t * t * w[i];
  }
  return ans;
}

void solve() {
  scanf("%d", &n);
  // std::cin >> n;
  double l = INT_MAX, r = INT_MIN;
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf", &x[i], &w[i]);
    // std::cin >> x[i] >> w[i];
    l = min(l, x[i]);
    r = max(r, x[i]);
  }
  while (r - l > eps) {
    double lmid = (l * 2 + r) / 3;
    double rmid = (l + r * 2) / 3;
    if (check(lmid) <= check(rmid))
      r = rmid;
    else
      l = lmid;
  }
  printf("%d\n", (int)round(check(l)));
  // std::cout << (int)round(check(l)) << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  scanf("%d", &t);
  // std::cin >> t;
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    // std::cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
