#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int s[2] {}, cnt[2] {}, mx[2] {};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s[a[i] % 2] += a[i];
    cnt[a[i] % 2]++;
    mx[a[i] % 2] = std::max(mx[a[i] % 2], a[i]);
  }
  if (!cnt[0]) {
    std::cout << mx[1] << '\n';
    return;
  }
  if (!cnt[1]) {
    std::cout << mx[0] << '\n';
    return;
  }
  std::cout << s[0] + s[1] - cnt[1] + 1 << '\n';
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