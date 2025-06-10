// date: 2025-03-20 19:13:38
// tag: 基于猜结论的模拟，神奇的基于平均值递增的guessforces，总之就是要猜到最优的情况是递增的，毕竟和一样，两个极值是可以弄到两边的

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::array<int, 2>> v;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int sum = a[i], cnt = 1;
    // while (!v.empty() && v.back()[0] / v.back()[1] < sum / cnt) {
    while (!v.empty() && v.back()[0] * cnt >= sum * v.back()[1]) {
      sum += v.back()[0];
      cnt += v.back()[1];
      v.pop_back();
    }
    if (sum % cnt == 0 || true) {
      v.push_back({sum, cnt});
    } else {
      v.push_back({sum / cnt, cnt - sum % cnt});
      v.push_back({sum / cnt + 1, sum % cnt});
    }
    // std::cerr << sum << ' ' << cnt << '\n';
  }
  // std::cerr << '\n';
  // for (auto [x, cnt] : v) {
  //   std::cerr << x << ' ' << cnt << '\n';
  // }
  std::cout << (v.back()[0] + v.back()[1] - 1) / v.back()[1] - (v.front()[0] / v.front()[1]) << '\n';
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