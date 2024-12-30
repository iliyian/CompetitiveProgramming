#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  int mn = *std::min_element(a.begin(), a.end());
  int mx = *std::max_element(a.begin(), a.end());
  int mn2 = -1, mx2 = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != mx && (a[i] > a[mx2] || mx2 == -1)) {
      mx2 = i;
    }
    if (a[i] != mn && (a[i] < a[mn2] || mn2 == -1)) {
      mn2 = i;
    }
  }
  // std::cout << mn2 << ' ' << mx2 << '\n';
  std::cout << mn2 + 2 + mx2 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}