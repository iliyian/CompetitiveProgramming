#include <bits/stdc++.h>
#define int long long

constexpr int N = 30000;

void solve() {
  int n, A, x;
  std::cin >> n >> A >> x;
  std::bitset<N + 1> dp;
  auto opt = [&](int x, int y, int op) {
    int ans = 0, t = 1;
    while (x || y) {
      ans = ans + t * (op == 1 ? std::min(x % A, y % A) : op == 2 ? std::max(x % A, y % A) : (x % A + y % A) % A);
      x /= A, y /= A;
      t *= A;
    }
    return ans;
  };
  dp[x] = 1;
  for (int i = 1; i <= n; i++) {
    int y;
    std::cin >> y;
    std::bitset<N + 1> ndp;
    for (int j = 0; j <= N; j++) {
      if (dp[j]) {
        ndp[opt(j, y, 1)] = 1;
        ndp[opt(j, y, 2)] = 1;
        ndp[opt(j, y, 3)] = 1;
      }
    }
    dp = ndp;
  }
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    if (dp[i]) {
      ans += i;
      // std::cerr << i << '\n';
    }
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