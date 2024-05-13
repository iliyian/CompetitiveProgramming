// date: 2024-05-12 15:53:50
// tag: 位运算，构造

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  auto check = [&](int x) -> bool {
    vector<int> c, d;
    for (int i = 1; i <= n; i++) {
      c.push_back(a[i] & x);
      d.push_back(b[i] & x ^ x);
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    return c == d;
  };

  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    ans ^= check(ans ^ (1 << i)) << i;
  }

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}