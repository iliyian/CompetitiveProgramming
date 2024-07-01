// date: 2024-06-23 14:04:00
// tag: mex，贪心，模拟

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  vector<int> posa(n + 1), posb(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    posa[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    posb[b[i]] = i;
  }

  // int truans = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = i; j <= n; j++) {
  //     int mex1 = 0, mex2 = 0;
  //     bitset<N + 1> vis;
  //     for (int k = i; k <= j; k++) {
  //       vis[a[k]] = true;
  //     }
  //     bool f = false;
  //     for (int k = 1; k <= n; k++) {
  //       if (!vis[k]) {
  //         mex1 = k;
  //         f = true;
  //         break;
  //       }
  //     }
  //     if (!f) {
  //       mex1 = n + 1;
  //     }
      
  //     vis.reset();
  //     for (int k = i; k <= j; k++) {
  //       vis[b[k]] = true;
  //     }
  //     f = false;
  //     for (int k = 1; k <= n; k++) {
  //       if (!vis[k]) {
  //         mex2 = k;
  //         f = true;
  //         break;
  //       }
  //     }
  //     if (!f) {
  //       mex2 = n + 1;
  //     }
  //     if (mex1 == mex2) {
  //       // cout << i << ' ' << j << ' ' << mex1 << '\n';
  //       truans++;
  //     }
  //   }
  // }
  // cout << truans << '\n';

  int ans = 0;
  auto calc = [&](int l, int r) {
    if (r < l) return 0ll;
    return (r - l + 1) * (r - l + 2) / 2;
  };

  int la = posa[1], ra = posa[1], lb = posb[1], rb = posb[1];
  int l = min(la, lb), r = max(ra, rb);
  ans += calc(1, l - 1) + calc(r + 1, n) + calc(l + 1, r - 1) ; // mex = 1
  for (int i = 1; i <= n - 1; i++) {
    la = min(posa[i], la), ra = max(posa[i], ra);
    lb = min(posb[i], lb), rb = max(posb[i], rb);

    // if ()

    if (la < posa[i + 1] && posa[i + 1] < ra || lb < posb[i + 1] && posb[i + 1] < rb || min(la, lb) < posa[i + 1] && posa[i + 1] < max(ra, rb)) {
      continue;
    }
    int rstop = min(posa[i + 1] > ra ? posa[i + 1] : n + 1, posb[i + 1] > rb ? posb[i + 1] : n + 1);
    int rlen = rstop - max(ra, rb);
    
    int lstop = max(posa[i + 1] < la ? posa[i + 1] : 0, posb[i + 1] < lb ? posb[i + 1] : 0);
    int llen = min(la, lb) - lstop;

    ans += max(0ll, rlen) * max(0ll, llen);
    // cout << i + 1 << ' ' << rlen * llen << '\n';
  }
  cout << ans + 1 << '\n';

  return 0;
}