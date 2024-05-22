// date: 2024-05-20 20:24:16
// tag: 分类讨论

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int k, x, y;
  cin >> k >> x >> y;
  if (k % 2 == 0) {
    cout << (y * 2 + x) / k << '\n';
  } else if (k == 1) {
    cout << x + y << '\n';
  } else {
    int cnt = y / (k / 2);
    int filled = min(cnt, x);
    x -= filled, y -= filled * (k / 2);
    if (!x) {
      cout << y / ((k + 1) / 2) + filled << '\n';
    } else {
      if (!y) {
        cout << filled + (x / k) << '\n';
      } else {
        if (x + y * 2 >= k) {
          filled++;
          x -= k - y * 2;
          // y = 0;
          cout << filled + (x / k) << '\n';
        } else {
          cout << filled << '\n';
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("L.in", "r", stdin);
  freopen("L.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}