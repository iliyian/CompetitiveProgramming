#include <bits/stdc++.h>
using namespace std;

long long x[10000], y[10000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  long double ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    for (int j = 0; j < i; j++)
      ans = min(ans,
        sqrtl((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
  }
  cout << fixed << setprecision(4) << ans;
  return 0;
}