#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int s[2] {}, ss[7] {};
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x != 4 && x != 6) {
      s[y]++;
      ss[x]++;
    }
  }
  if (s[0] > s[1]) std::cout << 0 << ' ' << s[0] << '\n';
  else if (s[1] > s[0]) std::cout << 1 << ' ' << s[1] << '\n';
  else std::cout << "LOVE " << s[0] << '\n';
  int mx = 0;
  for (int i = 1; i <= 6; i++) {
    mx = std::max(mx, ss[i]);
  }
  std::cout << mx << ' ';
  bool f = false;
  for (int i = 1; i <= 6; i++) {
    if (i == 4 || i == 6) continue;
    if (ss[i] == mx) {
      if (f) std::cout << ' ';
      std::cout << i;
      f = true;
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}