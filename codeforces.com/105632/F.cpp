#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, q;
  std::cin >> n >> k >> q;
  std::vector<int> a(n + 1), b(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    s[i] = s[i - 1] + b[i];
  }
  std::vector<int> finish1(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    finish1[i] = std::max(finish1[i - 1] + 1, a[i]) + b[i] - 1;
  }
  for (int i = n + 1; i <= n * 2; i++) {
    finish1[i] = std::max(finish1[i - 1] + 1, a[i - n] + k) + b[i - n] - 1;
  }
  // for (int i = 1; i <= n * 2; i++) {
  //   std::cerr << finish1[i] << ' ';
  // }
  // std::cerr << '\n';
  auto get = [&](int x) { // hour to day and hour
    return std::make_pair((x - 1) / k + 1, (x - 1) % k + 1);
  };
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (x <= 2) {
      int t = y;
      if (x == 2) {
        t += n;
      }
      auto ans = get(finish1[t]);
      std::cout << ans.first << ' ' << ans.second << '\n';
    } else {
      if (finish1[n * 2 - 1] >= k + a[n]) { // pushed
        int t = finish1[n * 2];
        t += (x - 3) * s[n]; // 完整的
        t += s[y];
        auto ans = get(t);
        if (x == 28 && y == 3) {
          std::cerr << t << '\n';
          return;
        }
        std::cout << ans.first << ' ' << ans.second << '\n';
      } else if (finish1[n] >= k + a[1]) {
        int t = finish1[y + n];
        t += (x - 2) * k;
        auto ans = get(t);
        std::cout << ans.first << ' ' << ans.second << '\n';
      } else {
        auto ans = get((x - 1) * k + finish1[y]);
        std::cout << ans.first << ' ' << ans.second << '\n';
      }
    }
  }
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