#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, k;
  std::cin >> n >> x >> k;
  std::string str;
  std::cin >> str;
  int ans = 0, t = -1;
  for (int i = 0; i < std::min(k, n); i++) {
    if (str[i] == 'L') x--;
    else x++;
    if (x == 0) {
      ans++;
      t = i + 1;
      break;
    }
  }
  if (t == -1) {
    std::cout << ans << '\n';
    return;
  }
  // std::cerr << t << ' ' << ans << '\n';
  for (int i = t; i < k; i++) {
    if (i - t >= n) break;
    if (str[i - t] == 'L') x--;
    else x++;
    // std::cerr << t << ' ' << x << '\n';
    if (x == 0) {
      // std::cerr << k << ' ' << i << '\n';
      ans += (k - t) / (i - t + 1);
      break;
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