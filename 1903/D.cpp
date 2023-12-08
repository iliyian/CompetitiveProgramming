// date: 2023/12/8
// tag: GREEDY, bit operate

#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int a[N], b[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  while (q--) {
    copy(b, b + n, a);
    int ma, ans = 0;
    cin >> ma;
    // k +- 1 does'nt matter
    for (int k = 60; k >= 0; k--) {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] >> k & 1 ^ 1) {
          // no more comparing for early bits
          // we didn't add
          // greedy
          sum += (1ll << k) - a[i];
          if (sum > ma) break;
        }
      }
      if (sum <= ma) {
        ma -= sum;
        for (int i = 0; i < n; i++)
          if (a[i] >> k & 1 ^ 1)
            // absolutely, each number have single transform
            // greedy
            a[i] = 0;
        ans ^= 1ll << k;
      }
      for (int i = 0; i < n; i++)
        if (a[i] >> k & 1)
          // we cannot add
          // greedy
          a[i] ^= 1ll << k;
    }
    cout << ans << '\n';
  }
}