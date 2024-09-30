#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  if (x % 2 && y % 2) {
    cout << "NO\n";
  } else if (x == 1 && y == 1 || (x == y * 2 && (y & 1)) || y == x * 2 && (x & 1)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}