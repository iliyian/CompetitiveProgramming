// date: 2025-01-25 16:55:49
// tag: 单调栈，贪心

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::stack<std::pair<int, int>> s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int t = a[i], cnt = 0;
    while (t % 2 == 0) cnt++, t /= 2;
    ans += a[i];
    ans %= mod;
    while (!s.empty() && (cnt >= 30 || (t << cnt) >= s.top().first)) { // 出题人的善意属于是，不然还得__int128
      // std::cerr << std::format("{} top:({},{})", i, s.top().first, s.top().second) << '\n';
      cnt += s.top().second;
      // std::cerr << std::format("cnt {}", cnt) << '\n';
      ans = (ans - s.top().first * qpow(2, s.top().second) % mod + mod) % mod;
      ans = (ans + s.top().first) % mod;
      s.pop();

      ans = (ans - a[i] + mod) % mod;
      a[i] = t * qpow(2, cnt) % mod;
      ans = (ans + a[i]) % mod;
    }
    if (cnt > 0) s.push({t, cnt});
    std::cout << ans << ' ';
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