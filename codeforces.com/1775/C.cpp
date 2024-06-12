// date: 2024-06-11 21:19:08
// tag: 位运算，lowbit

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  int an = n;
  for (;;) {
    if (an == x) {
      cout << n << '\n';
      return;
    } else if (an < x) {
      cout << -1 << '\n';
      return;
    } else {
      n += n & -n;
      an &= n;
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}