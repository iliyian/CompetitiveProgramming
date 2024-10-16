#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::array<int, 2>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    auto &[l, r] = a[i];
    std::cin >> l >> r;
  }
  std::sort(a.begin() + 1, a.end());
  int ans = 1;
  std::priority_queue<int> q;
  for (int i = 1; i <= n; i++) {
    auto &[l, r] = a[i];
    while (!q.empty() && -q.top() < l) q.pop();
    ans = ans * std::max(k - (int)q.size(), 0ll) % mod;
    q.push(-r);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("C.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}