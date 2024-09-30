#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, t;
  cin >> a >> b >> t;
  cout << int(ceil(abs(a - b) / 2.0 / t)) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}