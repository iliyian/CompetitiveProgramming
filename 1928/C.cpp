#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  int t = (n - x);
  if (t % 2) {
    cout << 0 << '\n';
    return;
  }
  t /= 2;
  int ans = 0;
  for (int i = 2; i * i <= t; i++) {
    if (t % i == 0) {
      t /= i;
      ans++;
    }
  }
  cout << ans << '\n';
}
// 7 -> 5
// 8 -> 4
// 1 2 3 4 5 6 5 4 3 2
// 


int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}