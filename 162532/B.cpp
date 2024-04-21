#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), x(n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n + 1);
  for (int i = 0; i <= n; i++) {
    if (i) {
      x[i] = a[i] ^ x[i - 1];
    } else {
      x[i] = a[i];
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    int t = i ^ (i + 1);
    int idx = __builtin_popcount(t);
    if (x[idx - 1] == 0) {
      ans[idx - 1] = 1;
    }
  }
  bool f = false;
  for (int i = 0; i < n; i++) {
    if (ans[i]) {
      f = true;
    }
    if (f) {
      cout << ans[i];
    }
  }
  if (!f) {
    if (x[n] == 0) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}