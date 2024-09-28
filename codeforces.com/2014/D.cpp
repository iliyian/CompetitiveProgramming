#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, d, k;
  std::cin >> n >> d >> k;
  std::vector<int> l(k + 1), r(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> l[i] >> r[i];
  }
  // for (int i = 1; i <= n; i++) {
  //   cnt[i] += cnt[i - 1];
  //   // std::cout << cnt[i] << ' ';
  // }
  // for (int i = 1; i <= n; i++) {
  //   cnt[i] += cnt[i - 1];
  // }
  // int mn = 1, mx = 1;
  // for (int i = 1; i <= n - d + 1; i++) {
  //   int j = i + d - 1;
  //   int c = cnt[j] - cnt[i - 1];
  //   if (c > cnt[mx + d - 1] - cnt[mx - 1]) {
  //     mx = i;
  //   }
  //   if (c < cnt[mn + d - 1] - cnt[mn - 1]) {
  //     mn = i;
  //   }
  // }
  // std::cout << mx << ' ' << mn << '\n';

  std::sort(l.begin() + 1, l.end());
  std::sort(r.begin() + 1, r.end());
  std::vector<int> cnt(n + 1);
  int mn = 1, mx = 1;
  for (int i = 1; i <= n - d + 1; i++) {
    int j = i + d - 1;
    auto lcnt = std::lower_bound(r.begin() + 1, r.end(), i) - r.begin() - 1;
    auto rcnt = l.end() - std::upper_bound(l.begin() + 1, l.end(), j);
    cnt[i] = k - lcnt - rcnt;
    if (cnt[i] < cnt[mn]) {
      mn = i;
    }
    if (cnt[i] > cnt[mx]) {
      mx = i;
    }
  }
  std::cout << mx << ' ' << mn << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("D.in", "r", stdin);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}