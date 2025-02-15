#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  int ans = 0, rcnt = 0, lcnt = 0, lsum = 0, rsum = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1') {
      ans += i - rcnt;
      rcnt++;
      rsum += i;
    }
  }
  auto getl = [&](int idx, int len) -> int {
    return (idx + idx - len + 1) * len / 2;
  };
  auto getr = [&](int idx, int len) -> int {
    return (idx + idx + len - 1) * len / 2;
  };
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1') {
      rsum -= i;
      rcnt--;
      // std::cerr << lcnt << ' ' << lsum << ' ' << rcnt << ' ' << rsum << '\n';
      // std::cerr << rsum - getr(i + 1, rcnt) + getl(i - 1, lcnt) - lsum << '\n';
      ans = std::min(ans, rsum - getr(i + 1, rcnt) + getl(i - 1, lcnt) - lsum);
      lcnt++;
      lsum += i;
    }
  }
  std::cout << ans << '\n';
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