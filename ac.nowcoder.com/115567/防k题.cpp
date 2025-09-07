#include <bits/stdc++.h>
#define int long long

void solve() {
  int x1, y1, z, x2, y2;
  std::cin >> x1 >> y1 >> z >> x2 >> y2;
  auto check = [&](int mid) -> bool {
    int cur = mid;
    int nowx1 = x1, nowx2 = x2, nowy1 = y1;
    bool f = true;
    auto do1 = [&](int x) {
      if (nowx1 > x) {
        nowx1 -= x;
        return;
      }
      cur--;
      nowx1 = x1;
    };
    while (1) {
      for (int i = 0; i < 3; i++) {
        do1(y2);
      }
      if (cur <= 0) return false;
      nowx2 -= nowy1 * cur;
      nowy1 += z;
      if (nowx2 <= 0) return true;
    }
  };
  int l = 1, r = 1e10, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
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