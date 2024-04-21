// date: 2024-03-03 16:35:55
// tag: 没有考虑到n可能很小
// 忘删对拍内容

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  int ans = n * k, sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += k % i;
  }
  cout << sum << '\n';
  for (int l = 1, r; l <= n; l = r + 1) {
    int t = k / l;
    if (t == 0) break;
    else r = min(k / t, n);
    ans -= (r - l + 1) * (r + l) * t / 2;
  }
  cout << ans << '\n';

  return 0;
}