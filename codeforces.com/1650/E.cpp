// date: 2024-04-26 12:03:56
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] - a[i - 1] < a[pos] - a[pos - 1]) {
      pos = i;
    }
  }

  auto calc = [&](int pos) {
    int mn = d, mx = 0;
    for (int i = 1; i <= n; i++) {
      if (i == pos) continue;
      int prv = i - 1;
      if (prv == pos) prv--;
      mn = min(mn, a[i] - a[prv] - 1);
      mx = max(mx, a[i] - a[prv] - 1);
    }
    return min(mn, max((mx - 1) / 2, d - a[n == pos ? n - 1 : n] - 1));
  };
  int ans = 0;
  ans = max(ans, calc(pos));
  if (pos > 1) {
    ans = max(ans, calc(pos - 1));
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}