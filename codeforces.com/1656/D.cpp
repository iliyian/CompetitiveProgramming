// date: 2024-04-27 09:21:37
// tag: 数学，构造

#include <bits/stdc++.h>
#define int long long
#define N 100000
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (__builtin_popcountll(n) == 1) {
    cout << -1 << '\n';
  } else if (n & 1) {
    cout << 2 << '\n';
  } else if (n % 3 == 0) {
    cout << 3 << '\n';
  } else {
    for (int i = 2; (i <= 1ll << 61); i <<= 1) {
      if (n * 2 % i == 0 && (n * 2 % (i << 1))) {
        int ans = min(i, n * 2 / i);
        cout << min(i, n * 2 / i) << '\n';
        assert((n - ans * (ans - 1) / 2) % ans == 0);
        return;
      }
    }
    cout << n << '\n';
    assert(false);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  // for (int i = 2; i <= 1e6; i++) {
  //   bool f = false;
  //   // cout << i << ' ';
  //   for (int j = 2; j * (j - 1) / 2 <= i; j++) {
  //     if ((i - j * (j - 1) / 2) % j == 0) {
  //       cout << j << '\n';
  //       f = true;
  //       break;
  //     }
  //   }
  //   if (!f) {
  //     cout << -1 << '\n';
  //   }
  // }
  // return 0;

  while (_--) {
    solve();
  }

  return 0;
}