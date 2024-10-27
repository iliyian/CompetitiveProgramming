#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  while (q--) {
    std::vector<int> b(n + 1);
    int x;
    std::cin >> x;
    for (int i = 1; i <= n; i++) {
      b[i] = a[i] % x;
    }
    std::sort(b.begin() + 1, b.end());
    std::cout << b[n % 2 ? n / 2 : n / 2 + 1] << ' ';
  }
  std::cout << '\n';
}

signed main() {
  freopen("I.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}