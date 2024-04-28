#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2), pre(n + 2), suf(n + 2);
  int l = 0, r = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
    if (pre[i] <= (k - 1) / 2 + 1) {
      l = i;
    }
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + a[i];
    if (suf[i] <= k / 2) {
      r = i;
    }
  }
  if (pre[n] <= k) {
    cout << n << '\n';
  } else {
    cout << l + (n - r + 1) << '\n';
  }
  // cout << (ans == -1 ? 0 : ans) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}