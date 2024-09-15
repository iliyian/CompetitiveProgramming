// date: 2024-09-12 09:48:19
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  freopen("main.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    auto &[y, x] = a[i];
    std::cin >> x >> y;
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<int> d(63);
  auto insert = [&](int x) {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return false;
        }
      }
    }
    return true; // can be xored
  };
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    auto &[y, x] = a[i];
    if (!insert(x)) {
      ans += y;
    }
  }
  std::cout << ans << '\n';
  return 0;
}