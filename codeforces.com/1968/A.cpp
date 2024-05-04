#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int x;
  cin >> x;
  int t = 1;
  for (int i = 1; i < x; i++) {
    if (gcd(t, x) + t < gcd(i, x) + i) {
      t = i;
    }
  }
  cout << t << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}