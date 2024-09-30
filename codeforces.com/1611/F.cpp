// date: 2024-04-17 11:53:19
// tag: 尺取

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ansl = 1, ansr = 0, ans = -1;
  for (int r = 1, l = 1, sum = a[1]; r <= n; r++, sum += a[r]) {
    while (l <= r && sum < -s) {
      sum -= a[l];
      l++;
    }
    if (l <= r) {
      if (r - l + 1 > ans) {
        ansr = r, ansl = l;
        ans = r - l + 1;
      }
    }
  }
  if (ansr < ansl) {
    cout << -1 << '\n';
    return;
  }
  cout << ansl << ' ' << ansr << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}