#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s(n + 1), s2(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
    s2[i] = s2[i - 1] + i * i;
  }
  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int l, r, k;
    cin >> l >> r >> k;
    int m = r - l + 1;
    int ans = s[r] - s[l - 1] + s2[m] - s2[m - k];
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