#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("A.in", "r", stdin);
  // freopen("A.out", "w", stdout);

  // for (int x = 1; x <= 30; x++) {
  //   for (int k = 1; k <= 4; k++) {

  int x, k;
  cin >> x >> k;

  if (x == 1) {
    cout << 1 << '\n';
    return 0;
    // continue;
  }

  int ans = k + 1, t = x;
  for (int i = 1; i <= k; i++) {
    int st = sqrt(t);
    ans++;
    if (st == 1) break;
    if (st * st != t) {
      ans += k - i;
    }
    t = st;
  }
  cout << ans << '\n';
  
  // set<int> s;
  // for (int i = 0; i <= k; i++) {
  //   int t = x;
  //   for (int j = 0; j <= k; j++) {
  //     s.insert(t);
  //     if (j < i) {
  //       t = sqrt(t);
  //     } else {
  //       t = t * t;
  //     }
  //   }
  // }
  // for (auto i : s) {
  //   cout << i << ' ';
  // }
  // cout << '\n' << s.size();

  // assert(s.size() == ans);

  //   }
  // }

  return 0;
}