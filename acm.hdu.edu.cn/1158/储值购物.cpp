#include <bits/stdc++.h>
#define int long long

void solve() {
  int v, w;
  std::cin >> v >> w;
  int ww = (w + 2) / 2;
  int ans = v / ww;
  int r = v - ans * ww;
  if (r > w - ww || !ans) {
    ans++;
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