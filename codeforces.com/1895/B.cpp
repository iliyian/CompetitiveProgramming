#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[201], x[101], y[101];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n * 2; i++)
    cin >> a[i];
  sort(a, a + n * 2);
  int ans = 0;
  for (int i = 1; i < n; i++)
    ans += abs(a[i] - a[i - 1]);
  for (int i = n * 2 - 1; i > n; i--)
    ans += abs(a[i] - a[i - 1]);
  
  for (int i = 0; i < n; i++)
    x[i] = a[i];
  for (int i = n; i < n * 2; i++)
    y[n * 2 - i - 1] = a[i];
  reverse(x, x + n);
  reverse(y, y + n);
  cout << ans << '\n';
  for (int i = 0; i < n; i++)
    cout << y[i] << ' ' << x[i] << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}