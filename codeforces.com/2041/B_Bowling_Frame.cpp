#include <bits/stdc++.h>
#define int long long

void solve() {
  int w, b;
  std::cin >> w >> b;
  auto check = [&](int mid) {
    if (w + b < mid * (mid + 1) / 2) return false;
    int ww = w, bb = b;
    for (int i = mid; i >= 1; i--) {
      if (ww < i && bb < i) return false;
      if (ww < bb) std::swap(ww, bb);
      ww -= i;
    }
    return true;
  };
  int l = 0, r = 1e7, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
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