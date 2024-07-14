// date: 2024-07-12 19:55:06
// tag: 二分，数学

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

std::pair<int, int> check(int a, int b, int n) {
  if (n == 1) return {1, a};
  return {
    std::min(__int128(inf), __int128(n - 2) * (a - b) + a + 1),
    std::min(__int128(inf), __int128(n - 1) * (a - b) + a)
  };
}

bool intersect(int l, int r, int mn, int mx) {
  // return !(l > mx || r < mx);
  return l <= mx && r >= mn;
}

void solve() {
  int n;
  std::cin >> n;
  int mx = inf, mn = 0;
  for (int i = 1; i <= n; i++) {
    int op, a, b, n;
    std::cin >> op;
    if (op == 1) {
      std::cin >> a >> b >> n;
      auto [l, r] = check(a, b, n);
      if (!intersect(l, r, mn, mx)) {
        std::cout << 0 << ' ';
      } else {
        std::cout << 1 << ' ';
        mx = std::min(mx, r), mn = std::max(mn, l);
      }
    } else {
      std::cin >> a >> b;
      int l = 1, r = inf, ans = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (check(a, b, mid).first <= mx) {
          l = mid + 1;
          ans = mid;
        } else {
          r = mid - 1;
        }
      }
      if (ans > 1 && intersect(check(a, b, ans - 1).first, check(a, b, ans - 1).second, mn, mx)) {
        std::cout << -1 << ' ';
      } else {
        std::cout << ans << ' ';
      }
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}