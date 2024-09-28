#include <bits/stdc++.h>
#define int long long

signed main() {
  int n;
  int ans = 0;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int t = i * i + j * j;
      int s = sqrt(t);
      if (t <= n * n && s * s == t) {
        ans++;
      }
    }
  }
  std::cout << ans << '\n';
  
  return 0;
}