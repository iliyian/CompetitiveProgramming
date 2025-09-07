#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  for (int i = 0; i < m; i++) {
    q.push(0);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int u = q.top(); q.pop();
    ans += u + a[i];
    ans %= mod;
    u += a[i];
    q.push(u);
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