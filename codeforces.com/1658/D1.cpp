// date: 2024-04-28 14:02:55
// tag: 位运算

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int l, r;
  cin >> l >> r;
  vector<int> a(r + 1), cnt1(21), cnt0(21);
  for (int i = 0; i <= r; i++) {
    cin >> a[i];
    for (int j = 20; j >= 0; j--) {
      if (a[i] >> j & 1) {
        cnt1[j]++;
      }
      if (i >> j & 1) {
        cnt0[j]++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 20; i++) {
    if (cnt1[i] != cnt0[i]) {
      ans ^= 1 << i;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}