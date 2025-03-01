// date: 2025-02-18 18:42:40
// tag: 挺少见的折半搜索

#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> a(n);
  // (b, a)
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].second;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first;
  }
  std::sort(a.begin(), a.end());
  // for (auto [B, A] : a) {
  //   std::cout << B << ' ' << A << '\n';
  // }
  int mid = n / 2;
  int rlen = n - mid;
  std::vector<std::vector<std::pair<int, int>>> lv(mid + 1);
  // std::vector<std::pair<int, int>> lv;
  int ans = 0;
  for (int S = 1; S < (1 << mid); S++) {
    int lans = 0, la = 0, pos = 0;
    for (int i = 0; i < mid; i++) {
      if (S >> i & 1) {
        la += a[i].second;
        lans += a[i].first * (pos++);
      }
    }
    if (la <= m) {
      ans = std::max(ans, lans);
    }
    lv[__builtin_popcountll(S)].push_back({la, lans});
  }
  // std::cout << mid << '\n';
  for (int len = 1; len <= mid; len++) {
    std::sort(lv[len].begin(), lv[len].end());
    // std::cout << len << '\n';
    // for (auto [w, v] : lv[len]) {
    //   std::cout << w << ' ' << v << '\n';
    // }
    for (int i = 0; i < lv[len].size() - 1; i++) {
      lv[len][i + 1].second = std::max(lv[len][i + 1].second, lv[len][i].second);
    }
  }
  for (int S = 1; S < (1 << rlen); S++) {
    int rsum = 0, rans = 0, ra = 0, pos = 0;
    for (int i = 0; i < rlen; i++) {
      if (S >> i & 1) {
        rsum += a[mid + i].first;
        ra += a[mid + i].second;
        rans += a[mid + i].first * (pos++);
        // if (S == 6) {
        //   std::cout << rsum << ' ' << rans << ' ' << ra << ' ' << i << ' ' << mid + i << '\n';
        // }
      }
    }
    if (ra <= m) {
      ans = std::max(ans, rans);
    }
    int resta = m - ra;
    if (resta < 0) continue;
    for (int len = 1; len <= mid; len++) {
      auto p = std::upper_bound(lv[len].begin(), lv[len].end(), std::pair{resta, LLONG_MAX}) - lv[len].begin() - 1;
      // if (S == 6) {
      //   std::cout << rsum << ' ' << rans << ' ' << ra << ' ' << resta << ' ' << p << ' ' << len * rsum + lv[len][p].second + rans << '\n';
      // }
      if (p < 0) continue;
      ans = std::max(ans, len * rsum + lv[len][p].second + rans);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}