// date: 2025-03-01 14:37:59
// tag: 哎值域，值域小的话不妨多想想值域，尤其是位运算的。顺便如果一维不够，真的不妨再多开一维试试，有时候真的时空都完全够

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), f(n + 1, LLONG_MIN);
  std::vector<std::vector<int>> mx(1024, std::vector<int>(1024, LLONG_MIN / 3));
  std::fill(mx[0].begin(), mx[0].end(), 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] ^= a[i - 1];
    for (int w = 0; w < 1024; w++) {
      f[i] = std::max(f[i], mx[w][a[i]] + i * (a[i] ^ w));
    }
    for (int w = 0; w < 1024; w++) {
      mx[a[i]][w] = std::max(mx[a[i]][w], f[i] - i * (a[i] ^ w));
    }
    ans += f[i];
  }
  std::cout << ans << '\n';
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