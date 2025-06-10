#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::multiset<int> s;
  std::string d = "01032025";
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
    if (s.count(0) >= 3 && s.count(1) >= 1 && s.count(2) >= 2 && s.count(5) >= 1 && s.count(3) >= 1) {
      if (ans == 0)
       ans = i;
    }
  }
  std::cout << ans << '\n';
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