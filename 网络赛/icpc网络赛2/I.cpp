#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n == 0 || (n & -n) >= 4) {
    std::cout << "NO\n";
    return;
  }
  std::vector<int> ans(32);
  bool f = false;
  ans[31] = 1;
  int pos = std::__lg(n & -n);
  std::cout << "YES\n";
  int prv = 1;
  for (int i = 31; i >= pos; i--) {
    if (prv == 1) {
      ans[i] = 1;
    } else {
      ans[i] = -1;
    }
    prv = (n >> i & 1);
  }
  for (int i = 0; i <= 31; i++) {
    std::cout << ans[i] << ' ';
    if ((i + 1) % 8 == 0) {
      std::cout << '\n';
    }
  }
}

signed main() {
  freopen("I.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}