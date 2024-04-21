#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  int ans = 0, minn = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i - 1] > a[i]) ans += a[i - 1] - a[i];
  }
  ans += a[n] - 1;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}