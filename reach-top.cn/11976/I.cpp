#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int prv = 0, ans = 0, cur = 0;
  std::vector<int> v;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x != prv) {
      cur = 1;
    } else {
      cur++;
    }
    if (cur > ans) {
      v.clear();
      v.push_back(x);
      ans = cur;
    } else if (cur == ans) {
      v.push_back(x);
    }
    prv = x;
  }
  std::sort(v.begin(), v.end());
  std::cout << ans << ' ' << v.front() << '\n';
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}