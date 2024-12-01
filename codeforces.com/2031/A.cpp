#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (vec.empty() || a[i] >= vec.back()) vec.push_back(a[i]);
    else *std::upper_bound(vec.begin(), vec.end(), a[i]) = a[i];
  }
  std::cout << n - vec.size() << '\n';
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