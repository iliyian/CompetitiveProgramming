// date: 2024-11-28 22:49:29
// tag: 二分

#include <bits/stdc++.h>
#define int long long

int get(int a, int b) {
  if (a > b) return -1;
  if (a < b) return 1;
  return 0;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> mx(n + 1);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += get(cur, a[i]);
    mx[i] = std::max(mx[i - 1], cur);
  }
  auto check = [&](int mid) {
    for (int i = n; i >= 1; i--) {
      if (mx[i] >= mid) return true;
      if (mid > a[i]) mid++;
      else mid--;
    }
    return false;
  };

  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}