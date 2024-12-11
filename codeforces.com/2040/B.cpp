#include <bits/stdc++.h>
#define int long long

constexpr int N = 6e5;

void solve() {
  int n;
  std::cin >> n;
  int ans = 1, cnt = 1;
  while (cnt < n) {
    cnt = (cnt + 1) * 2;
    ans++;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
