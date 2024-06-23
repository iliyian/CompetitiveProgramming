// date: 2024-06-21 15:31:28
// tag: dp，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n + 1);
  vector<array<int, 2>> f(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  auto up = [&](int x) {
    if (x <= s) return x;
    if (x <= s * 2) return s;
    return x - s;
  };

  auto lo = [&](int x) {
    if (x <= s) return 0ll;
    if (x <= s * 2) return x - s;
    return s;
  };

  f[2][0] = a[1] * lo(a[2]), f[2][1] = a[1] * up(a[2]);
  for (int i = 3; i <= n - 1; i++) {
    f[i][0] = min(f[i - 1][1] + lo(a[i - 1]) * lo(a[i]), f[i - 1][0] + up(a[i - 1]) * lo(a[i]));
    f[i][1] = min(f[i - 1][1] + lo(a[i - 1]) * up(a[i]), f[i - 1][0] + up(a[i - 1]) * up(a[i]));
  }
  cout << min(f[n - 1][0] + up(a[n - 1]) * a[n], f[n - 1][1] + lo(a[n - 1]) * a[n]) << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}