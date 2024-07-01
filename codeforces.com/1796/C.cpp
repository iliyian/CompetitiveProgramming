// date: 2024-06-23 18:00:36
// tag: 二分，数论

#include <bits/stdc++.h>
#define int long long
using namespace std;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int a, b;
  cin >> a >> b;
  int maxlen = 0;
  while (a << (maxlen + 1) <= b) {
    maxlen++;
  }
  cout << maxlen + 1 << ' ';

  int l = a, r = b, mx = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid << maxlen <= b) {
      mx = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  int cnt = mx - a + 1;
  // cout << cnt << ' ';

  l = a, r = b, mx = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid << maxlen <= b * 2 / 3) {
      mx = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cnt += maxlen * max(0ll, mx - a + 1);
  cout << cnt << '\n';
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