// date: 2025-04-08 00:47:15
// tag: 神奇卡常题，少见的O(n^2log^2n)的复杂度，dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, mx;
  std::cin >> n >> mx;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second >> a[i].first;
  }
  std::sort(a.begin() + 1, a.end());
  auto check = [&](int mid) {
    for (int i = 1; i + mid - 1 <= n; i++) {
      std::multiset<int> s1;
      int sum1 = 0;
      for  (int j = i; j <= n; j++) {
        s1.insert(a[j].second);
        sum1 += a[j].second;
        if (s1.size() > mid) {
          sum1 -= *s1.rbegin();
          s1.erase(--s1.end());
        }
        if (j - i + 1 >= mid) {
          int sum = sum1 + a[j].first - a[i].first;
          if (sum <= mx) {
            return true;
          }
        }
      }
    }
    return false;
  };
  int l = 0, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}