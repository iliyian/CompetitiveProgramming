#include <bits/stdc++.h>
#define int long long
using namespace std;

// 5, 3

void solve() {
  int x, y;
  cin >> x >> y;
  if (y % 2 == 0) {
    int t = y / 2;
    if (x <= t * 7) {
      cout << t << '\n';
    } else {
      cout << t + (x - t * 7 + 14) / 15 << '\n';
    }
  } else {
    int t = y / 2;
    if (x <= t * 7 + 11) {
      cout << t + 1 << '\n';
    } else {
      cout << t + 1 + (x - (t * 7 + 11) + 14) / 15 << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}