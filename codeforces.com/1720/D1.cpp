// date: 2024-05-12 14:28:45
// tag: max(x-y,y-x) <= x^y <= x+y
// dp优化，位运算

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    for (int j = max(0ll, i - 500); j < i; j++) {
      if ((a[j] ^ i) < (a[i] ^ j)) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
  }
  int ans = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    ans = max(ans, f[i]);
  }
  cout << ans + 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}