#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  scanf("%lld,%lld", &a, &b);
  int cnt = 0, ans = 0;
  for (int i = a; i <= b; i++) {
    int cur = 0, t = i;
    while (t > 1) {
      if (t % 2 == 0) {
        t /= 2;
      } else {
        t = 3 * t + 1;
      }
      cur++;
    }
    if (cur > cnt) {
      cnt = cur;
      ans = i;
    }
  }
  std::cout << ans << '\n' << cnt + 1 << '\n';
  while (ans) {
    std::cout << ans << "->";
    if (ans == 1) break;
    if (ans % 2 == 0) {
      ans /= 2;
    } else {
      ans = 3 * ans + 1;
    }
  }
}

signed main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}