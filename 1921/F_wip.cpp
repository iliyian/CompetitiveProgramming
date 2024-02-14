// date: 2024/02/13 18:57:56
// tag: 后缀和与看似暴力的正解，这题也只可能后缀和，一点也不dp
// wa#01: 题读错了，d<=n，只需要保证k<2即可保证s+d*(k-1)<=n，
// 我忽视了d=n的情况，还以为题目出错了...
// mle#02: 爆了，应该离线处理，只处理询问到的d的，否则甚至会t

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  vector<vector<int>> pre(n + 1, vector<int>(n + 1));
  vector<array<int, 3>> ask(q);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> ask[i][j];
    }
  }
  for (int d = 1; d <= n; d++) {
    for (int t = n; t >= n - d + 1; t--) {
      for (int k = 1;; k++) {
        int x = t - d * (k - 1);
        if (x < 1) break;
        pre[d][x] = (x + d <= n ? pre[d][x + d] : 0) + a[x];
      }
    }
  }
  for (int t = 0; t < q; t++) {
    int s, d, k;
    cin >> s >> d >> k;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
      int x = s + d * (i - 1);
      ans += pre[d][x];
    }
    // trim
    ans -= (s + d * k <= n ? pre[d][s + d * k] : 0) * k;
    cout << ans << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}