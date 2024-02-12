#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    cin >> c[i];
  int cur = 0, ax = 0, bx = 0, cx = 0;
  for (int i = 0; i < n; i++) {
    int t = ax | a[i];
    bool f = true;
    for (int j = (1 << 30); j > 0; j >>= 1) {
      if ((j & t) && !(j & x)) {
        f = false;
        break;
      }
    }
    if (!f) break;
    ax |= a[i];
  }
  for (int i = 0; i < n; i++) {
    int t = bx | b[i];
    bool f = true;
    for (int j = (1 << 30); j > 0; j >>= 1) {
      if ((j & t) && !(j & x)) {
        f = false;
        break;
      }
    }
    if (!f) break;
    bx |= b[i];
  }
  for (int i = 0; i < n; i++) {
    int t = cx | c[i];
    bool f = true;
    for (int j = (1 << 30); j > 0; j >>= 1) {
      if ((j & t) && !(j & x)) {
        f = false;
        break;
      }
    }
    if (!f) break;
    cx |= c[i];
  }
  cout << ((ax | bx | cx) == x ? "YES" : "NO") << '\n';
}
// 10101
// 


int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}