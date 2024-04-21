// 差分模板，差分的前缀和是原数组

#include <bits/stdc++.h>
using namespace std;

int a[5000001], b[5000001], c[5000001];

int main() {
  freopen("data.in", "r", stdin);
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] - a[i - 1];
  }
  for (int i = 0; i < p; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    b[x] += z;
    b[y + 1] -= z;
  }
  int ans = 1 << 30;
  for (int i = 1; i <= n; i++) {
    c[i] = c[i - 1] + b[i];
    ans = min(ans, c[i]);
  }
  cout << ans;
  return 0;
}