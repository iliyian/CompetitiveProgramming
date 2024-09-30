#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt[40];

void solve() {
  int t, v;
  cin >> t >> v;
  if (t == 1) {
    cnt[v]++;
  } else {
    int p = 0, t = v, presum = 0;
    bool f = true;
    while (t) {
      int x = t & 1ll; t >>= 1ll;
      presum += cnt[p] << p;
      if (x) {
        if (presum >= (1ll << p)) {
          presum -= 1ll << p;
        } else {
          cout << "NO\n";
          f = false;
          break;
        }
      }
      p++;
    }
    if (f)
      cout << "YES\n";
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}