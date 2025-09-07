// date: 2025-06-19 15:00:12
// tag: 怎么什么玩意都可以差分啊？mx都行？
// 怎么前缀和也可以用左闭右开区间啊？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, S, x;
  std::cin >> n >> S >> x;
  std::vector<int> a(n), s(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }
  auto solve = [&](int x) {
    int ans = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      if (a[j] > x) {
        j++;
      } else {
        while (j < n && a[j] <= x) {
          j++;
        }
        // std::cerr << i << ' ' << j << '\n';
        std::map<int, int> mp;
        mp[s[i]] = 1;
        for (int k = i; k < j; k++) {
          ans += mp[s[k + 1] - S];
          mp[s[k + 1]]++;
        }
      }
    }
    return ans;
  };
  std::cout << solve(x) - solve(x - 1) << '\n';
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