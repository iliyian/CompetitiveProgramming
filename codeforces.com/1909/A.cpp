#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  
  bitset<4> vis;
  // r, u, l, d
  bool l = false, r = false, u = false, d = false;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > 0) r = true;
    if (x < 0) l = true;
    if (y > 0) u = true;
    if (y < 0) d = true;
  }
  if (r && l && u && d) {
    cout << "NO\n";
  } else cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}