// date: 2024-05-15 21:01:05
// tag: 模拟，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = k + 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  for (int i = k - 1; i >= 1; i--) {
    s[i] = s[i + 1] + a[i];
  }

  int sl = a[k], sr = a[k], l = k - 1, r = k + 1;
  while (1 <= l && r <= n) {
    bool f = false;
    while (r <= n && sl + s[r] >= 0) sr = max(sr, a[k] + s[r++]), f = true;
    while (1 <= l && sr + s[l] >= 0) sl = max(sl, a[k] + s[l--]), f = true;
    if (!f) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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