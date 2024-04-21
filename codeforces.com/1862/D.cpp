#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n;
  cin >> n;
  // n = x*(x-1)/2 + k; min(x + k); 
  long long x = (1 + sqrt(1 + 8 * n)) / 2;
  cout << x + n - x * (x - 1) / 2 << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}