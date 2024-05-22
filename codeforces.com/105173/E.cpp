// date: 2024-05-21 13:59:14
// tag: 

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  string str;
  cin >> n >> k >> str;
  int t = 0;
  for (int i = 0; i < n; i++) {
    t += (str[i] == '1');
  }
  int l = 0, r = (1 << k) - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    int ch = mid - __builtin_popcount(mid);
    if (ch < t) l = mid + 1;
    else if (ch > t) r = mid - 1;
    else {
      ans = mid;
      break;
    }
  }
  if (ans == -1) {
    cout << "None" << '\n';
  } else {
    if (ans % 2) ans--;
    // cout << t << '\n';
    // cout << ans - __builtin_popcount(ans) << '\n';
    for (int i = k - 1; i >= 0; i--) {
      cout << (ans >> i & 1);
    }
    cout << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  
  // for (int i = 2; i <= 1000; i += 2) {
  //   cout << i << ' ' << i - __builtin_popcount(i) << '\n';
  // }

  // return 0;

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}