// date: 2024-05-05 22:48:10
// tag: 反集，滑动窗口

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  if (k <= n) {
    int l = 1, r = k, cur = 0;
    for (int i = l; i <= r; i++) {
      cur += a[i];
    }
    ans = max(ans, cur);
    while (r <= n - 1) {
      l++, r++;
      cur -= a[l - 1];
      cur += a[r];
      ans = max(ans, cur);
    }
    ans += (k - 1) * k / 2;
    cout << ans << '\n';
  } else {
    for (int i = 1; i <= n; i++) {
      ans += a[i];
    }
    ans += n * k - n * (n + 1) / 2;
    cout << ans << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}