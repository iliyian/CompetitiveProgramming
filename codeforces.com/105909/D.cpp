// date: 2025-05-25 20:33:19
// tag: 感觉上是一种比较细节的双指针。但终究还是双指针，大体框架还是要有自信的。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  auto check = [&](int mid) -> int {
    int sum = 0;
    for (int r = 1, l = 1; r <= n; r++) {
      int cnt = r - l;
      while (l + 1 <= r && a[r] - a[l] > mid) l++, cnt--;
      sum += cnt;
    }
    return sum;
  };
  // check(5);
  int l = 0, r = 1e9 + 10, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid) >= k) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  // std::cerr << ans << '\n';
  int res = (check(ans) - k) * (-ans);
  l = 1, r = 1;
  for (int r = 1, l = 1; r <= n; r++) {
    int cnt = r - l, now = cnt * a[r] - (s[r - 1] - s[l - 1]);
    while (l + 1 <= r && a[r] - a[l] > ans) {
      now -= a[r] - a[l];
      l++;
    }
    res += now;
  }
  std::cout << res << '\n';
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