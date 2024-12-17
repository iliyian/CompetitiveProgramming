#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(k + 1);
  std::vector<int> t(n + 1), c(n + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> t[i] >> c[i];
  }
  auto check = [&](int mid) -> bool {
    std::vector<int> b(k + 1);
    for (int i = 1; i <= mid; i++) {
      b[t[i]] += c[i];
    }
    auto c = a;
    int rest = 0;
    for (int i = 1; i <= k; i++) {
      int cur = std::max(0ll, (c[i] - b[i]) / 3);
      c[i] -= cur * 3;
      rest += cur;
    }
    for (int i = 1; i <= k; i++) {
      int need = std::max(b[i] - c[i], 0ll);
      rest -= need;
      if (rest < 0) return false;
    }
    return true;
  };
  int l = 0, r = n, ans = -1;
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
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}