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
  int loop = 10;
  std::vector<int> finish(n * loop + 1);
  for (int i = 1; i <= loop; i++) {
    for (int j = 1; j <= n; j++) {
      int idx = (i - 1) * n + j;
      finish[idx] = std::max(finish[idx - 1] + 1, a[j] + (i - 1) * k) + b[j] - 1;
    }
  }
  auto get = [&](int x) { // hour to day and hour
    return std::make_pair((x - 1) / k + 1, (x - 1) % k + 1);
  };
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (x <= loop) {
      auto ans = get(finish[(x - 1) * n + y]);
      std::cout << ans.first << ' ' << ans.second << '\n';
    } else {
      int cir = finish[loop * n] - finish[(loop-1) * n];
      int t = cir * (x - (loop + 1)) + finish[loop * n] + finish[(loop-1) * n + y] - finish[(loop-1) * n];
      auto ans = get(t);
      std::cout << ans.first << ' ' << ans.second << '\n';
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