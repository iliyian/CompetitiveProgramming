#include <bits/stdc++.h>
#define int long long

void solve() {
  int l, r;
  std::cin >> l >> r;
  int ans = 0;
  std::vector<int> a(r + 1), vis(r + 1);
  int msb = 64;
  for (int i = r; i >= 0; i--) {
    msb = std::min<int>(msb, 63 - __builtin_clzll(i));
    int t = i ^ (1ll << msb) ^ ((1ll << msb) - 1);
    if (vis[i] || vis[t]) continue;
    vis[i] = vis[t] = 1;
    a[i] = t;
    a[t] = i;
  }
  for (int i = 0; i <= r; i++) {
    ans += i | a[i];
  }
  std::cout << ans << '\n';
  for (auto i : a) {
    std::cout << i << ' ';
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