#include <bits/stdc++.h>
// #define int long long

int d[(int)2e6 + 1] {}, a[(int)2e6 + 1], pos[(int)2e6 + 1];

void solve() {
  int n;
  std::cin >> n;
  // std::vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto add = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i)
      d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i)
      ans += d[i];
    return ans;
  };
  int ans = 1;
  auto work = [&]() {
    for (int i = 1; i <= n; i++) {
      d[i] = 0;
      pos[a[i]] = i;
    }
    int minp = n + 1;
    for (int i = n; i >= 1; i--) {
      // std::cerr << i << ' ' << minp << '\n';
      if (minp < pos[i]) {
        ans = std::max(ans, pos[i] - minp + 1 - (query(pos[i]) - query(minp - 1)) + 1);
      } else {
        minp = pos[i];
      }
      add(pos[i], 1);
    }
    std::fill(d + 1, d + 1 + n, 0);
  };
  work();
  std::reverse(a + 1, a + n + 1);
  work();
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