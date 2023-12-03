#include <bits/stdc++.h>
#define N 200001
#define int long long
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int l = a[n - 1], r = a[n], ans = 0;
  // int ans = 0;
  for (int i = n - 2; i >= 0; i--) {
    // ans += ceil((a[i] + 0.1) / a[i + 1]);
    if (l > r) {
      int cnt, p;
      if (l > r * 2) {
        p = (int)(ceil(log2(double(l) / r)));
      } else p = 1;
      cnt = (1 << p) - 1;

      if (r == 1) cnt = l - 1, r = 1;
      else r = l >> p;

      ans += cnt;
      l = a[i];
    } else {
      l = a[i], r = a[i + 1];
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}