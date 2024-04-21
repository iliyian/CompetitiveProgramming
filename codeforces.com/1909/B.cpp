#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool mo1 = false, mo2 = false;
  int g = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g = gcd(a[i], g);
    if (a[i] & 1ll) mo1 = true;
    else mo2 = true;
  }
  if (mo1 && mo2) {
    cout << 2 << '\n';
  // } else if (g != 1) {
  //   cout << g * 2 << '\n';
  } else {

    for (int k = 0; k <= 60; k++) {
      bool f = true;
      map<int, bool> vis;

      for (int i = 0; i < n; i++) {
        int m = a[i] % (1ll << k);
        vis[m] = true;
        if (vis.size() >= 3) {
          f = false;
          break;
        }
      }

      if (f && vis.size() == 2) {
        cout << (1ll << k) << '\n';
        return;
      }
    }

  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}