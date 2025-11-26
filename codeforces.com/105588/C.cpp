#include <bits/stdc++.h>
#define int long long

using i128 = __int128;

void solve() {
  int n, k;
  std::cin >> n >> k;
  int round = 0;
  while (n > 0) {
    if (i128(k) * k <= n) {
      n -= (n + k - 1) / k;
      round++;
    } else {
      i128 t = (n + k - 1) / k;
      i128 next_n = (t - 1) * k;
      i128 cnt = (n - next_n + t - 1) / t;
      n -= cnt * t;
      round += cnt;
    }
  }
  round--;
  // std::cerr << round << '\n';
  int ans = 1;
  while (round > 0) {
    if (i128(k) * k <= round) {
      ans = ans + (ans + k - 2) / (k - 1);
      round--;
    } else {
      i128 t = (ans + k - 2) / (k - 1);
      i128 next_ans = t * (k - 1) + 1;
      i128 cnt = (next_ans - ans + t - 1) / t;
      if (cnt > round) {
        cnt = round;
      }
      ans += cnt * t;
      round -= cnt; 
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}