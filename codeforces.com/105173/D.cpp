#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    cout << "lose\n";
  }

  return 0;

  // freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  auto check = [&](auto self, int rest, int xsum) {
    if (!rest) {
      return xsum == 0;
    }
    for (int i = 1; i <= min(rest, 3ll); i++) {
      int t = rest - i;
      bool f = true;
      if (!t) {
        if ((xsum ^ i)) {
          f = false;
        }
      } else {
        for (int j = 1; j <= min(t, 3ll); j++) {
          if (!self(self, t - j, xsum ^ i)) {
            f = false;
            break;
          }
        }
      }
      if (f) {
        return true;
      }
    }
    return false;
  };

  for (int i = 1; i <= 100; i++) {
    cout << check(check, i, 0) << ' ';
  }

  // int _;
  // cin >> _;

  // while (_--) {
  //   solve();
  // }

  return 0;
}