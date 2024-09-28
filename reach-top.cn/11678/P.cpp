#include <bits/stdc++.h>
#define int long long

signed main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int x, cur = 0;
  std::cin >> x;
  for (int i = 1; i <= n; i++) {
    if (x >= a[i]) {
      x -= a[i];
      cur++;
    }
  }
  std::cout << cur << '\n';
  
  return 0;
}