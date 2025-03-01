#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  std::iota(a.begin(), a.end(), 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[j] ^= i;
    }
    for (int j = 0; j < n; j++) {
      std::cerr << a[j] << ' ';
    }
    std::cerr << '\n';
    for (int j = 0; j < n; j++) {
      a[j] ^= i;
    }
  }

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
