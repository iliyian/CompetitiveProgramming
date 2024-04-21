// date: 2023/12/10
// wa#01: not greedy enough

#include <bits/stdc++.h>
#define N 300005
#define int long long
using namespace std;

int a[N], pre[N], suf[N], n;

bool check(int mid) {
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    if (mid < a[i]) return false;
    if (mid - i + 1 < a[i]) l = max(l, i);
    if (mid - (n - i) < a[i]) r = min(r, i);
  }
  return l <= r;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int l = 0, r = 0x3f3f3f3f3f3f3f3f, ans = -1;
  while (l <= r) {
    int mid = l + (r - l >> 1ll);
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  // int t; cin >> t;
  int t = 1;
  while (t--) solve();
  return 0;
}