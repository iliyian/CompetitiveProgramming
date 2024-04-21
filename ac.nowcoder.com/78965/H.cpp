#include <bits/stdc++.h>
#define int long long
using namespace std;

struct H {
  int s, id, t, w;
  bool operator < (const H &b) const {
    __int128 rp = __int128(w) * b.t, rp2 = __int128(b.w) * t;
    if (rp != rp2) {
      return rp < rp2;
    }
    if (s != b.s) {
      return s > b.s;
    }
    return id > b.id;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int n;
  cin >> n;
  vector<H> a(n + 1);
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s >> a[i].t;
    a[i].id = i;
  }
  vector<int> ans(n + 1);
  for (int t = 1, cur = 0; t <= n; t++) {     
    H mx = {0, 0, 0, 0};
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        if (mx.id == 0) {
          mx = a[i];
        } else {
          mx = max(mx, a[i]);
        }
      }
    }
    if (t == 1) cur = a[mx.id].s;
    vis[mx.id] = true;
    ans[mx.id] = cur;
    cur += a[mx.id].t;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        a[i].w = cur - a[i].s;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}