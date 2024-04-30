// date: 2024-04-29 12:35:02
// tag: 模拟，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int l = 1e9, r = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l = min(l, a[i]);
    r = max(r, a[i]);
  }
  auto check = [&](int h) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
      int d = h - a[i];
      if (d & 1) {
        cnt1++;
      }
      cnt2 += d / 2;
    }
    if (cnt2 == cnt1 || cnt2 == cnt1 - 1) {
      return cnt2 + cnt1;
    }
    int ans = min(cnt1, cnt2) * 2;
    cnt1 -= ans / 2, cnt2 -= ans / 2;
    if (!cnt2) {
      return ans + cnt1 * 2 - 1;
    }
    if (cnt2 % 3 == 0) {
      return ans + cnt2 / 3 * 4;
    } else if (cnt2 % 3 == 1) {
      return ans + (cnt2 - 1) / 3 * 4 + 2;
    } else {
      return ans + (cnt2 - 2) / 3 * 4 + 3;
    }
  };
  cout << min({check(r), check(r + 1)}) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}