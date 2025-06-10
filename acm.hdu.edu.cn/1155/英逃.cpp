#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), pre(n + 2), suf(n + 3);
  std::vector<std::vector<int>> mx(20, std::vector<int>(n + 1));
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[0][i] = a[i];
    if (i >= 2) {
      pre[i] = pre[i - 1] + std::abs(a[i] - a[i - 1]);
    }
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + std::abs(a[i] - a[i - 1]);
  }
  for (int i = 1; i <= 19; i++) {
    for (int j = n - (1 << (i - 1)); j >= 1; j--) {
      mx[i][j] = std::max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
    }
  }
  auto getmx = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[len][l], mx[len][r - (1 << len) + 1]);
  };
  auto check = [&](int mid) {
    if (mid == 0) return pre[n] <= k;
    for (int l = 1; l + mid - 1 <= n; l++) {
      int r = l + mid - 1, mx = getmx(l, r);
      int sum = pre[l - 1] + suf[r + 2];
      if (l > 1) {
        sum += std::abs(mx - a[l - 1]);
      }
      if (r < n) {
        sum += std::abs(mx - a[r + 1]);
      }
      if (sum <= k) {
        return true;
      }
    }
    return false;
  };
  int l = 0, r = n, ans = -1;
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