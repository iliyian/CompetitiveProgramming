// date: 2024-04-22 19:36:59
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> k(n + 1), h(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<int> f(n + 1);
  f[n] = h[n];
  auto calc = [&](int x, int y) {
    return (x + y) * (y - x + 1) / 2;
  };
  for (int i = n - 1; i >= 1; i--) {
    f[i] = max(h[i], f[i + 1] - (k[i + 1] - k[i]));
  }
  int ans = calc(1, f[1]), d = f[1];
  for (int i = 2; i <= n; i++) {
    int t = k[i] - k[i - 1];
    if (f[i] <= t) {
      ans += calc(1, f[i]);
      d = f[i];
    } else {
      ans += calc(d + 1, d + t);
      d += t;
    }
  }
  cout << ans << '\n';
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