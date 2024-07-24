#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (b < a && c < d || a < b && d < c) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}