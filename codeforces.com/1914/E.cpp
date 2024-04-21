// date: 2024/02/15 19:11:22
// tag: 根据奇偶性找规律的题，与两数之后有关，这类型的题好像很频繁

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return a[x] + b[x] > a[y] + b[y];
  });
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      ans += a[id[i]] - 1;
    } else {
      ans -= b[id[i]] - 1;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}