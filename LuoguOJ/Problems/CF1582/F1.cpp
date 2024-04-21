// date: 2024-03-28 13:20:13
// tag: 桶优化的位运算dp
// wa#01: ？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？/
// cnmb

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F1.in", "r", stdin);
  freopen("F1.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), mn(1024, INT_MAX);
  vector<bool> vis(512);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vis[a[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    mn[a[i]] = min(mn[a[i]], a[i]);
    for (int S = 1; S < 512; S++) {
      if (mn[S ^ a[i]] < a[i]) {
        // assert(S ^ a[i] < 512);
        mn[S] = min(mn[S], a[i]);
        vis[S] = true;
      }
    }
  }
  vis[0] = true;
  int ans = 0;
  for (int i = 0; i < 512; i++) {
    if (vis[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < 512; i++) {
    if (vis[i]) {
      cout << i << ' ';
    }
  }

  return 0;
}