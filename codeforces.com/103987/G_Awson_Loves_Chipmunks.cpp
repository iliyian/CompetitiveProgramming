// date: 2025-03-01 16:15:18
// tag: 可恶的双指针，可恶的卡常

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, m;
  std::cin >> n >> k >> m;
  std::vector<int> a(n + 1), l, r;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int sum = 0;
  for (int i = k; i >= 1; i--) {
    sum += a[i];
    l.push_back(sum);
  }
  r.push_back(0);
  sum = 0;
  for (int i = k + 1; i <= n; i++) {
    sum += a[i];
    r.push_back(sum);
  }
  std::sort(l.begin(), l.end());
  std::sort(r.begin(), r.end());
  // for (auto i : l) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  // for (auto i : r) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  auto check = [&](int mid) -> bool {
    int _l = 0, _r = r.size() - 1, cnt = 0;
    while (_l < l.size()) {
      while (_r >= 1 && r[_r] + l[_l] > mid) _r--;
      if (l[_l] + r[_r] <= mid) {
        cnt += _r + 1;
      }
      // std::cerr << mid << ' ' << _l << ' ' << _r << '\n';
      _l++;
    }
    // std::cerr << mid << ' ' << cnt << '\n';
    return cnt >= m;
  };
  int _l = -1e16, _r = 1e16, ans = -1;
  while (_l <= _r) {
    int mid = (_l + _r) / 2;
    if (check(mid)) _r = mid - 1, ans = mid;
    else _l = mid + 1;
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