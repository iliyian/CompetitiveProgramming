#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::set<int> s;
  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      std::cin >> x;
      if (i == 1 || j == n) {
        s.insert(x);
        ans.push_back(x);
      }
    }
  }
  int x = 1;
  while (s.count(x)) x++;
  std::cout << x << ' ';
  for (auto i : ans) std::cout << i << ' ';
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