#include <bits/stdc++.h>
#define int long long

signed main() {
  int x, y, w, k;
  std::cin >> x >> y >> w >> k;
  int sum = 0;
  for (int i = 1;; i++) {
    sum += i / w;
    if (i >= x) sum += y;
    if (sum >= k) {
      std::cout << i << '\n';
      return 0;
    }
  }
  return 0;
}