#include <bits/stdc++.h>
using namespace std;

int a[100001], d[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, p = 0, q = 0;
  cin >> n;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], a[0] = a[1];
    d[i] = a[i] - a[i - 1];
    if (d[i] < 0) p += -d[i];
    if (d[i] > 0) q += d[i];
  }
  cout << max(p, q) << '\n' << abs(p - q) + 1;
  return 0;
}