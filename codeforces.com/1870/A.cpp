#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  if (k > x + 1 || n < k) {
    cout << -1 << '\n';
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i < k) ans += i;
    else ans += (k == x ? k - 1 : x);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}