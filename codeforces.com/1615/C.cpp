// date: 2024-04-19 15:08:16
// tag: 模拟，暴力，

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  int s1 = 0, s2 = 0, s = 0;
  for (int i = 0; i < n; i++) {
    s1 += a[i] == '1', s2 += b[i] == '1';
    s += a[i] != b[i];
  }
  int ans = INT_MAX;
  if (s1 == s2) ans = s;
  if (n - s1 + 1 == s2) ans = min(ans, 1 + n - s - 1); // 同异互换
  cout << (ans == INT_MAX ? -1 : ans) << '\n';
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