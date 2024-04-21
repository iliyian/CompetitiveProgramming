#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  int l = (k + 1) * k / 2, r = (n * 2 - k + 1) * k / 2;
  if (x < l || x > r) cout << "NO" << '\n';
  else cout << "YES" << '\n'; 
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}