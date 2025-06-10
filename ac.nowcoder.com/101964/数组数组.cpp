#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int ans = 1;
  int c1 = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (n & 1 && a[(n + 1) / 2] == -1 && std::count(a.begin() + 1, a.end(), 1) == n - 1) {
    std::cout << "Bob\n";
  } else {
    std::cout << "Alice\n";
  }
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