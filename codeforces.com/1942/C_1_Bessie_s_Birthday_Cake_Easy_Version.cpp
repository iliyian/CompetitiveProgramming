#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(x + 1);
  for (int i = 1; i <= x; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  a.push_back(a[1] + n);
  int ans = x - 2;
  for (int i = 2; i <= x + 1; i++) {
    if (a[i] - a[i - 1] == 2) {
      ans++;
    }
  }
  ans = std::max(ans, 0ll);
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