#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y, k;
  cin >> x >> y >> k;
  if (x >= y) {
    cout << x << '\n';
    return;
  }
  if (x + k <= y) {
    cout << y + (y - x - k) << '\n';
    return;
  }
  if (x <= y) {
    cout << y << '\n';
    return;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}