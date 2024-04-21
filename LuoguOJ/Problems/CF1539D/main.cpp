// date: 2024-03-30 09:48:31
// tag: 模拟，贪心，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin() + 1, a.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
    return x.second < y.second;
  });
  int ans = 0, cnt = 0;
  int l = 1, r = n;
  while (l <= r) {
    while (l <= r && cnt >= a[l].second) {
      ans += a[l].first;
      cnt += a[l].first;
      l++;
    }
    if (l <= r) {
      int t = a[l].second - cnt;
      t = min(t, a[r].first);

      ans += t * 2;
      cnt += t;
      a[r].first -= t;

      if (!a[r].first) {
        r--;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}