#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int b, c, h;
  cin >> b >> c >> h;
  if (h + c >= b - 1) {
    cout << b * 2 - 1 << '\n';
  } else {
    cout << (h + c) * 2 + 1 << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}