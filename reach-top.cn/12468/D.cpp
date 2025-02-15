#include <bits/stdc++.h>
#include <cctype>
#define int long long

void solve() {
  int a, b, n;
  std::cin >> n >> a >> b;
  std::vector<int> vec(n + 1);
  int mx = INT_MIN;
  for (int i = 1; i <= n; i++) {
    std::cin >> vec[i];
    mx = std::max(mx, vec[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (i >= a && i <= b) std::cout << mx << ' ';
    else std::cout << vec[i] << ' ';
  }
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