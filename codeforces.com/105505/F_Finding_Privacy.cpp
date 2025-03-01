#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> k >> n;
  if (k > (n + 1) / 2 || k < (n + 2) / 3) {
    std::cout << "*\n";
    return;
  }
  std::string ans(n, '-');
  int p = 1;
  for (int i = 1; i < n; i += 3) {
    ans[i] = 'X';
    k--;
  }
  if (n % 3 == 1) ans.back() = 'X', k--;
  p = 1;
  // std::cerr << ans << ' ' << k << '\n';
  while (k) {
    // std::cerr << p << '\n';
    if (p < n) {
      ans[p] = '-';
    }
    ans[p - 1] = 'X';
    if (p + 1 < n) ans[p + 1] = 'X';
    p += 6;
    k--;
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