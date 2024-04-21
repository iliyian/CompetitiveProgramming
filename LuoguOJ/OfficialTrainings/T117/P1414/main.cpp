#include <bits/stdc++.h>
using namespace std;

array<int, 1000001> a, ans;

int main() {
  freopen("data.in", "r", stdin);
  int n, inf = -1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++, inf = max(inf, x);
  }
  for (int i = 1; i <= inf; i++) {
    int sum = 0; // factor
    for (int j = 1; i * j <= inf; j++) sum += a[i * j];
    ans[sum] = i;
  }
  for (int i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}