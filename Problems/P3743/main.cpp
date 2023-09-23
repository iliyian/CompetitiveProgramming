#include <bits/stdc++.h>
using namespace std;

int n, p, a[100000], b[100000];

bool check(double mid) {
  double sum = mid * p;
  for (int i = 0; i < n; i++) {
    if (b[i] >= mid * a[i]) continue;
    sum -= (a[i] * mid - b[i]);
  }
  return sum >= 0;
}

int main() {
  cin >> n >> p;
  long long sum = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i], sum += a[i];
  if (sum <= p) {
    cout << -1;
    return 0;
  }
  double l = 0, r = 2499975000;
  while (l + 0.000001 < r) {
    double mid = l + (r - l) / 2;
    if (check(mid)) l = mid;
    else r = mid;
  }
  cout << fixed << setprecision(10) << l;
  return 0;
}