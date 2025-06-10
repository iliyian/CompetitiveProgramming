// date: 2025-04-09 21:40:56
// tag: 还是比较难以预料会出现的bitset优化可行性背包dp+二分。这玩意真是正解吗？还真是。不过也不需要二分，考虑到只有两个背包，另一个直接贪心即可。

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

void solve() {
  int n, w, f;
  std::cin >> w >> f >> n;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  auto check = [&](int mid) -> bool {
    std::bitset<N + 1> dp;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      dp |= dp << a[i];
    }
    for (int i = std::min(sum, mid * w); i >= sum - f * mid; i--) {
      if (dp[i]) {
        return true;
      }
    }
    return false;
  };
  int l = 1, r = sum, ans = -1;
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