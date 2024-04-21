#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int lmax = 1, rmax = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      lmax = i;
    } else {
      break;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i + 1] == a[i]) {
      rmax = n - i + 1;
    } else {
      break;
    }
  }
  if (n == 1) {
    cout << 0 << '\n';
  } else if (a[1] == a[n]) {
    cout << max(0ll, n - lmax - rmax) << '\n';
  } else {
    cout << min(n - lmax, n - rmax) << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}