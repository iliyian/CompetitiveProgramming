#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 1) {
    cout << 0 << '\n';
    return;
  }
  if (m <= n) {
    if (k == 2) {
      cout << m << '\n';
    } else
      cout << 0 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}