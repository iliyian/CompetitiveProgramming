#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2), mx(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[i] = std::max(a[i], mx[i - 1]);
  }
  for (int i = n; i >= 1; i--) {
    a[i] += a[i + 1];
    std::cout << a[i + 1] + mx[i] << ' ';
  }
  std::cout << '\n';
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