// tmd, 这份代码clang++20就TLE,g++14就能ac，太tmd离谱了
// diagnostics 慢得离谱

#include <bits/stdc++.h>
using namespace std;

bitset<100001> vis;
int a[100001], leftm[100001], rightm[100001], v[100001];
int x[100001], sumr[100001];

void solve() {
  int n, vlen = 0;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[vlen++] = a[i];
  }

  vis.reset();

  sort(v, v + vlen);
  // cerr << "vlen=" << vlen << '\n';
  int len = unique(v, v + vlen) - v;

  for (int i = 1; i <= n; i++) {
    x[i] = lower_bound(v, v + len, a[i]) - v;
    if (!vis[x[i]]) leftm[x[i]] = i, vis[x[i]] = true;
    rightm[x[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    sumr[i] = sumr[i - 1] + (rightm[x[i]] == i);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (leftm[x[i]] == i) {
      ans += sumr[n] - sumr[i - 1];
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}