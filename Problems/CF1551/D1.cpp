// date: 2024-04-01 13:09:37
// tag: 递推，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == m % 2) {
    cout << (k % 2 ? "NO" : "YES") << '\n';
  } else if (n % 2) {
    cout << ((k >= m / 2 && (k - m / 2) % 2 == 0) ? "YES" : "NO") << '\n';
  } else {
    cout << ((n * (m - 1) / 2 >= k && (n * (m - 1) / 2 - k) % 2 == 0)
      ? "YES" : "NO") << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}