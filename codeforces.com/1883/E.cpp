#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans = 0, prev2 = 0, prev;
  cin >> prev;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    int t = max(0.0, ceil(log2(prev * 1.0 / a) + prev2));
    prev2 = t, prev = a;
    ans += t;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}