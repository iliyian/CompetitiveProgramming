#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, ans = 0, m = 0;
  cin >> n >> k;
  m += n; n = 0;
  ans += m;
  while (m >= k) {
    n += m / k;
    m %= k;
    m += n;
    ans += n;
    n = 0;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  int _ = 1;
  while (_--) solve();
}