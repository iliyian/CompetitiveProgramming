// date: 2024-03-14 11:41:24
// tag: lcm
// wa#01: 没特判
// tle#02: map的桶被t了...卡常有点过分了
// wa#03: 没有加cnt[a[i]]，没有用上桶...

#include <bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), cnt(m + 1), lcm(m + 1);
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > m) continue;
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > m || vis[a[i]]) continue;
    vis[a[i]] = true;
    for (int j = 1; j * a[i] <= m; j++) {
      lcm[j * a[i]] += cnt[a[i]];
    }
  }
  int maxlcm = 0, maxcnt = 0;
  for (int i = 1; i <= m; i++) {
    if (lcm[i] > maxcnt) {
      maxcnt = lcm[i];
      maxlcm = i;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (maxlcm % a[i] == 0) {
      ans.push_back(i);
    }
  }
  if (maxlcm == 0) {
    cout << 1 << ' ' << 0;
    return 0;
  }
  cout << maxlcm << ' ' << ans.size() << '\n';
  for (auto idx : ans) {
    cout << idx << ' ';
  }

  return 0;
}