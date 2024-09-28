#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int cnt = (n - k + 1 + n) * k / 2;
  std::cout << (cnt & 1 ? "NO" : "YES") << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("B.in", "r", stdin);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}