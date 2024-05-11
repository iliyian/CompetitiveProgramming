// date: 2024-05-10 15:45:41
// tag: 数论，补集

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
using namespace std;

vector<vector<int>> fac(N + 1);

void solve() {
  int l, r;
  cin >> l >> r;
  int len = r - l + 1;
  int ans = len * (len - 1) * (len - 2) / 6;
  // (3, 4, 6), (6, 10, 15)
  for (int k = l + 2; k <= r; k++) {
    if (k % 6 == 0) {
      ans -= k / 2 >= l;
    }
    if (k % 15 == 0) {
      ans -= k / 5 * 2 >= l;
    }
    auto it = lower_bound(fac[k].begin(), fac[k].end(), l) - fac[k].begin();
    int cnt = fac[k].size() - 1 - it;
    ans -= cnt * (cnt - 1) / 2;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E1.in", "r", stdin);
  freopen("E1.out", "w", stdout);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j * i <= N; j++) {
      fac[j * i].push_back(i);
    }
  }

  // for (int i = 1; i <= N; i++) {
  //   for (int j = i + 1; j <= N; j++) {
  //     for (int k = j + 1; k <= N; k++) {
  //       int l = lcm(lcm(i, j), k);
  //       if (l == k * 2 && l < i + j + k) {
  //         cout << i << ' ' << j << ' ' << k << '\n';
  //       }
  //     }
  //   }
  // }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}