// date: 2024-03-24 15:54:37
// tag: 丢番图方程

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  int g;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1) {
      a[i] -= a[1];
      g = gcd(g, a[i]);
    } else {
      g = 0;
    }
  }
  if ((k - a[1]) % g) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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