// date: 2024-02-28 01:09:47
// tag: 考试结束后14分钟AC了。。。
// 三分，这种带条件的前缀和似乎三分是个不错的选择，注意三分和get函数别写错即可
// 主要是tmd二分太难写了

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int L, u;
    cin >> L >> u;
    int x = s[L - 1] + u;
    int l = L, r = n;
    auto get = [&s, &u, &L](int x) {
      int sum = 0, d = s[x] - s[L - 1];
      return d * u - d * (d - 1) / 2;
    };
    int ans = -1;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      int rmid = mid + 1, lmid = mid - 1;
      if (get(lmid) < get(rmid)) l = mid;
      else r = mid;
    }
    cout << (get(l) >= get(r) ? l : r) << ' ';
  }
  cout << '\n';
}
// 3 4 8 9 14 23

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}