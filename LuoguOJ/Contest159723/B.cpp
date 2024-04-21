#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  if (y - x <= 24000) {
    cout << 5 << '\n';
  } else if (y - x <= 24000 * 1.5) {
    cout << 6 << '\n';
  } else if (y - x <= 24000 * 2) {
    cout << 8 << '\n';
  } else if (y - x <= 24000 * 3) {
    cout << 11 << '\n';
  } else {
    double d = y - x;
    // d <= 24000 * 4x;
    cout << ceil(d / 96000) * 13 << '\n';
  }
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