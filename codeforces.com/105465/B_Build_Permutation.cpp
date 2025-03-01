#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> mp;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  // std::cerr << sum << '\n';
  // std::cerr << sum << '\n';
  if (sum * 2 % n) {
    std::cout << -1 << '\n';
    return;
  }
  sum = sum / n * 2;
  // std::cerr << sum << '\n';
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    mp[a[i]] = i;
    if (mp[sum - a[i]]) {
      ans[i] = mp[sum - a[i]];
      ans[mp[sum - a[i]]] = i;
      mp[sum - a[i]] = 0;
      mp[a[i]] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!ans[i]) {
      std::cout << -1 << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
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