// date: 2023/12/10
// wa#01: not greedy enough

#include <bits/stdc++.h>
#define N 300005
#define int long long
using namespace std;

int a[N], pre[N], suf[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    pre[i] = a[i] + i - 1;
    suf[i] = a[i] + n - i;
  }
  for (int i = 1; i <= n; i++)
    suf[i] = max(suf[i], suf[i - 1]);
  for (int i = n; i >= 1; i--)
    pre[i] = max(pre[i], pre[i + 1]);
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    int cur = a[i];
    cur = max(cur, max(pre[i + 1], suf[i - 1]));
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  // int t; cin >> t;
  int t = 1;
  while (t--) solve();
  return 0;
}