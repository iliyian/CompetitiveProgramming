// date: 2025-03-02 11:45:37
// tag: 神奇的O(n)做法

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> ans(n + 1);
  int c1 = 0;
  // 自然而然的平滑过渡，保证对于任意时刻都满足和不增
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x == 1) {
      std::cout << c1 + 1 << ' ';
      c1 = (c1 + 1) % k;
    } else {
      c1 = (c1 + k - 1) % k;
      std::cout << c1 + 1 << ' ';
    }
  }
  std::cout << '\n';
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