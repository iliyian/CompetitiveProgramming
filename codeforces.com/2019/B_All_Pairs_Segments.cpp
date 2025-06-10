#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  std::map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mp[i * (n - i + 1) - 1]++;
  }
  for (int i = 2; i <= n; i++) {
    mp[(i - 1) * (n - i + 1)] += a[i] - a[i - 1] - 1;
  }
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << mp[x] << ' ';
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