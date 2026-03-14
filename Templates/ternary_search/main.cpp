// date: 2024/02/13 15:21:56
// tag: wa#01: 三分查找的r开小了
// wa#02: 在求和之外的地方出现了signed integer overflow，
// 果然tmd是直接define int long long更省事和好用吗？？？？？？？
// tmd我完全可以在考场上做出来D的啊艹

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, b, x;
  cin >> n >> b >> x;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  auto get = [&](const int &quad) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int h = (c[i] - 1) / quad + 1;
      int r = h * quad - c[i];
      int sum = h * h * ((quad - r) * (quad - r - 1) / 2)
        + (h - 1) * (h - 1) * (r * (r - 1) / 2)
        + h * (h - 1) * r * (quad - r);
      ans += sum * b;
    }
    return ans - (quad - 1) * x;
  };
  int l = 1, r = 0x3f3f3f3f3f3f3f3f;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int lmid = mid - 1, rmid = mid + 1;
    if (get(lmid) < get(rmid)) l = mid;
    else r = mid;
  }
  cout << max(get(l), get(r)) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}