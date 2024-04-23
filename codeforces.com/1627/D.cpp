// date: 2024-04-23 10:11:35
// tag: 用欧拉筛

#include <bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> g(N), a(n + 1);
  bitset<N> vis;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vis[a[i]] = true;
  }
  int cnt = 0;
  for (int i = 1; i <= (int)1e6; i++) {
    if (!vis[i]) {
      for (int j = 1; i * j <= (int)1e6; j++) {
        if (vis[i * j]) {
          cnt++;
          g[i] = gcd(g[i], i * j);
        }
      }
    }
  }
  int ans = 0;
  cerr << cnt << '\n';
  for (int i = 1; i <= 1000000; i++) {
    ans += !vis[i] && g[i] == i;
  }
  cout << ans << '\n';

  return 0;
}