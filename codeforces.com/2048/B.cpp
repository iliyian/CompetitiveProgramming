#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int cur = 1;
  for (int i = k; i <= n; i += k) {
    a[i] = cur++;
  }
  for (int i = 1; i <= n; i++) {
    if (!a[i]) a[i] = cur++;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
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
