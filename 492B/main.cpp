#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  int maxd = a[0] * 2;
  for (int i = 1; i < n; i++)
    maxd = max(maxd, a[i] - a[i - 1]);
  maxd = max(maxd, (l - a[n - 1]) * 2);
  cout << fixed << setprecision(10) << maxd / 2.0;
  return 0;
}