#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  int u = 0, v = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i], u ^= a[i];
  for (int i = 0; i < m; i++) {
    cin >> b[i], v |= b[i];
  }
  int val = 0;
  for (int i = 0; i < n; i++)
    val ^= (a[i] | v);
  if (n & 1 ^ 1) cout << val << ' ' << u << '\n';
  else cout << u << ' ' << val << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}