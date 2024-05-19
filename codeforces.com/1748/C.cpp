// date: 2024-05-18 13:18:54
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> s(n + 1);
  map<int, int> cnt;
  int ans = 0, mx = 0;
  bool f = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    if (f && !s[i] && a[i]) ans++;
    if (a[i] == 0) {
      if (!f) {
        ans += mx;
      }
      cnt.clear();
      f = false;
      mx = 0;
    }
    cnt[s[i]]++;
    mx = max(mx, cnt[s[i]]);
    // cerr << s[i] << " \n"[i == n];
  }
  if (!f) {
    ans += mx;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}
