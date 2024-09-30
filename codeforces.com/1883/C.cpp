#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int ans = 0x3f3f3f3f;
  int div2 = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int t = (k - a % k) % k;
    if (a % 2 == 0) div2++;
    ans = min(ans, t);
  }

  if (k == 4) {
    ans = max(0, min(ans, 2 - div2));
  }

  cout << ans << '\n';
}

signed main() {
  freopen("C.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}