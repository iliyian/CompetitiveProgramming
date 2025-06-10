// date: 2025-05-07 21:54:09
// tag: 没啥意思的水题，哎

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n + 1), d(m + 1), f(k + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> d[i];
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> f[i];
  }
  std::sort(d.begin() + 1, d.end());
  std::sort(f.begin() + 1, f.end());
  int mx = -1, cnt = 0, mx2 = -1, pos = -1;
  for (int i = 2; i <= n; i++) {
    if (a[i] - a[i - 1] > mx) {
      mx2 = mx;
      mx = a[i] - a[i - 1];
      pos = i;
      cnt = 1;
    } else if (a[i] - a[i - 1] == mx) {
      cnt++;
    } else {
      mx2 = std::max(mx2, a[i] - a[i - 1]);
    }
  }
  if (cnt > 1) {
    std::cout << mx << '\n';
    return;
  }
  auto check = [&](int mid) -> bool {
    int l = a[pos] - mid, r = a[pos - 1] + mid;
    for (int i = 1; i <= m; i++) {
      if (d[i] > r) break;
      auto p = std::lower_bound(f.begin() + 1, f.end(), l - d[i]) - f.begin();
      if (p != k + 1 && d[i] + f[p] <= r) {
        return true;
      }
    }
    return false;
  };
  int l = std::max(mx2, (mx + 1) / 2), r = mx, ans = mx;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
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