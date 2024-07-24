#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << max({a, b, c}) - min({a, b, c}) << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}