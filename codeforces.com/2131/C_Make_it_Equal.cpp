#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::multiset<int> a, b;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a.insert(std::min(k - x % k, x % k));
  }
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    b.insert(std::min(k - x % k, x % k));
  }
  std::cout << (a == b ? "YES" : "NO") << '\n';
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