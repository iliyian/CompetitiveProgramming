#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[0] == a[1]) cout << a[2] << '\n';
  else cout << a[0] << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}