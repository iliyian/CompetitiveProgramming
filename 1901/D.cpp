#include <bits/stdc++.h>
#define N 300005
#define int long long
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  int mx = -1, idx = -1;
  vector<int> idxs;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > mx) {
      mx = a[i], idx = i;
    }
  }
  int l = -1, r = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == mx) {
      r = i;
      if (l == -1) l = i;
    }
  }
  // int ans = -1, l = idxs.front(), r = idxs.back();
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    // auto pin = lower_bound(idxs.begin(), idxs.end(), i);
    // int dist = max(abs(idxs.front() - i), abs(idxs.back() - i));
    int pin = abs(l - i) < abs(r - i) ? l : r;
    int d = i <= pin ? n - i : i - 1;
    // int d = max(n - i, i - 1);
    // if (a[i] == mx) d = 0;
    ans = max(ans, d + a[i]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  // int t; cin >> t;
  int t = 1;
  while (t--) solve();
  return 0;
}