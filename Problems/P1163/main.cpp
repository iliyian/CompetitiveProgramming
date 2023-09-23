#include <bits/stdc++.h>
using namespace std;

int n, m, k;

bool check(double mid) {
  double ans = 0;
  double sum = n;
  for (int i = 0; i < k; i++)
    sum = sum * (1 + mid) - m;
  return sum > 0;
}

int main() {
  cin >> n >> m >> k;
  double l = 0, r =  5;
  while (l + 0.0001 < r) {
    double mid = l + (r - l) / 2.0;
    if (check(mid)) r = mid;
    else l = mid;
  }
  cout << fixed << setprecision(1) << l * 100;
  return 0;
}