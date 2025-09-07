#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    in[x]++, in[y]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] > 3) {
      std::cout << 0 << '\n';
      return;
    } else if (in[i] != 3) {
      ans++;
    }
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