// date: 2024-02-28 00:01:47
// tag: 没判断大于的情况无限循环,没判断重复的情况wa
// 没判断i*i==x
// 相同的情况判断错了

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, l;
  cin >> a >> b >> l;
  int ans = 0, acnt = 0, bcnt = 0, ax = 1, bx = 1;
  int x = l;
  if (a == b) {
    if (l % a == 0) {
      int y = 1;
      for (;; y++) {
        ax = ax * a;
        if (ax > l || l % ax) {
          break;
        }
      }
      cout << y << '\n';
      return;
    }
    cout << 1 << '\n';
    return;
  }

  for (acnt = 0;; acnt++) {
    if (x % a == 0) {
      x /= a;
    } else break;
  }

  x = l;
  for (bcnt = 0;; bcnt++) {
    if (x % b == 0) {
      x /= b;
    } else break;
  }
  set<int> s;
  for (int i = 0; i <= acnt; i++) {
    if (i) ax *= a;
    bx = 1;
    for (int j = 0; j <= bcnt; j++) {
      if (j) bx *= b;
      s.insert(ax * bx);
    }
  }
  ans = 0;
  for (int i = 1; i * i <= l; i++) {
    if (l % i == 0) {
      ans += s.count(l / i);
      if (i != l / i) {
        ans += s.count(i);
      }
      
    }
  }
  cout << ans << '\n';
  x = l;
  // cout << (acnt + 1) * (bcnt + 1) << '\n';


  // return;
  // if (a == b) {
  //   if (l % a == 0) {
  //     for (int x = 1;; x++) {
  //       ax = ax * a;
  //       if (ax == l) {
  //         cout << x + 1 << '\n';
  //         return;
  //       }
  //     }
  //   }
  //   cout << 0 << '\n';
  //   return;
  // }
  // for (int x = 0;; x++) {
  //   if (x > 0) {
  //     ax = ax * a;
  //   }
  //   if (ax > l) {
  //     break;
  //   }
  //   bx = 1;
  //   if (l % ax) {
  //     continue;
  //   }
  //   for (int y = 0;; y++) {
  //     if (y > 0) {
  //       bx = bx * b;
  //     }
  //     if (bx * ax > l) {
  //       break;
  //     }
  //     if (l / ax % bx == 0) {
  //       ans++;
  //     }
  //   }
  // }
  // cout << ans << '\n';
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