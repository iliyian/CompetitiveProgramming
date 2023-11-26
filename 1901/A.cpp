#include <bits/stdc++.h>
#define N 200
using namespace std;

int a[N], n, x;

void solve() {
  cin >> n >> x;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) ans = max(ans, abs(a[i] - a[i - 1]));
    else ans = max(ans, a[i]);
    if (i == n - 1) ans = max(ans, abs(x - a[i]) * 2);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}