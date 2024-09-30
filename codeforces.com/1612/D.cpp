// date: 2024-04-17 13:00:17
// tag: 数学

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, x;
  cin >> a >> b >> x;
  while (a && b) {
    if (a < b) swap(a, b);
    if (a > x && (a - x) % b == 0 || a == x || b == x) {
      cout << "YES\n";
      return;
    }
    a %= b;
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}