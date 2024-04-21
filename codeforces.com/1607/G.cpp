// date: 2024-04-16 13:05:15
// tag: 数学，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(n + 1);
  int S = 0, L = 0, R = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    S += a[i] - b[i] + m;
    L += max(0ll, m - b[i]);
    R += min(a[i], m);
  }
  if (S <= L * 2) {
    cout << L * 2 - S << '\n';
    for (int i = 1; i <= n; i++) {
      int x = max(0ll, m - b[i]);
      cout << x << ' ' << m - x << '\n';
    }
  } else if (S >= R * 2) {
    cout << S - R * 2 << '\n';
    for (int i = 1; i <= n; i++) {
      int x = min(a[i], m);
      cout << x << ' ' << m - x << '\n';
    }
  } else {
    vector<int> ans(n + 1);
    int T = 0;
    for (int i = 1; i <= n; i++) {
      ans[i] = max(0ll, m - b[i]);
      T += ans[i];
    }
    int req = S / 2 - T;
    for (int i = 1; i <= n; i++) {
      int l = max(0ll, m - b[i]), r = min(a[i], m);
      if (r - l >= req) {
        ans[i] = l + req;
        req = 0;
      } else {
        ans[i] = r;
        req -= r - l;
      }
    }
    cout << S % 2 << '\n';
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ' << m - ans[i] << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}