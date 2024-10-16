#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int l = std::__lg(a[i] & -a[i]);
    a[i] >>= l;
    cnt += l;
  }
  std::sort(a.begin() + 1, a.end());
  auto check = [&](int mid) -> int {
    int cur = 0;
    for (int i = n; i >= n - mid + 1; i--) {
      if (a[i] >= mid) continue;
      int t = (mid + a[i] - 1) / a[i];
      cur += std::__lg(t);
      if (__builtin_popcountll(t) > 1) cur++;
      if (cur > cnt) return false;
    }
    return cur <= cnt;
  };
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("H.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}