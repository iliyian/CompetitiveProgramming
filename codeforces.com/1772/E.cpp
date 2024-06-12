// date: 2024-06-08 20:26:33
// tag: 博弈

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int c1 = 0, c2 = 0, d = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c1 += a[i] != i;
    c2 += a[i] != n - i + 1;
    d += a[i] != i && a[i] != n - i + 1;
  }
  // cout << c1 << ' ' << c2 << ' ' << d << '\n';
  if (c1 + d <= c2) {
    cout << "First\n";
  } else if (c2 + d < c1) {
    cout << "Second\n";
  } else {
    cout << "Tie\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}