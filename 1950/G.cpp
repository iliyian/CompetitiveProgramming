// date: 2024-03-29 08:20:41
// tag: 状压dp
// wa#01: 想成树的直径
// wa#02: 想成环的大小
// wa#03: 转移条件遗漏

#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<string, string>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  vector<int> f(1 << n), e(n);
  for (int i = 0; i < n; i++) {
    f[1 << i] |= 1 << i;
    for (int j = 0; j < n; j++) {
      if (a[i].first == a[j].first || a[i].second == a[j].second) {
        e[i] |= 1 << j;
      }
    }
  }
  int ans = n - 1;
  for (int s = 1; s < (1 << n); s++) {
    if (f[s]) {
      ans = min(ans, n - __builtin_popcount(s));
    }
    for (int i = 0; i < n; i++) {
      if ((~s >> i & 1) && (f[s] & e[i])) {
        f[s | 1 << i] |= 1 << i;
      }
    }
  }

  cout << ans << '\n';
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