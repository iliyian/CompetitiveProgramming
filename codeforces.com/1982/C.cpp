#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, L, R;
  cin >> n >> L >> R;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cur = 0, sum = 0, ans = 0;
  int l = 1, r = 1;
  while (r <= n) {
    sum += a[r];
    if (L <= sum && sum <= R) {
      ans++;
      sum = 0;
      l = r + 1;
    } else if (sum > R) {
      while (l <= r && sum > R) {
        sum -= a[l++];
      }
      if (L <= sum && sum <= R) {
        ans++;
        sum = 0;
        l = r + 1;
      }
    }
    r++;
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}