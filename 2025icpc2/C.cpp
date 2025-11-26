#include <bits/stdc++.h>
#define int long long

void solve() {
  int S;
  std::cin >> S;
  std::array<int, 8> a;
  std::array<int, 3> c{0, 0, 0};
  for (int i = 1; i < 8; i++) {
    std::cin >> a[i];
    if (i == 1) {
      c[0] += a[i];
    }
    if (i == 2) {
      c[1] += a[i];
    }
    if (i == 4) {
      c[2] += a[i];
    }
  }
  auto put = [&](int &x, int &a, int &b, int mid) {
    if (mid <= x) return;
    if (a >= mid - x) {
      a -= mid - x;
      x = mid;
    } else {
      x += a;
      a = 0;
      if (b >= mid - x) {
        b -= mid - x;
        x = mid;
      } else {
        x += b;
        b = 0;
      }
    }
  };
  auto check = [&](int mid) -> bool {
    int p[3] = {0, 1, 2};
    do {
      auto op = [&](int x, int i, std::array<int, 8> &_a, std::array<int, 3> &d) {
        if (x == 0) {
          if (i >> 0 & 1) {
            put(d[0], _a[3], _a[5], mid);
          } else {
            put(d[0], _a[5], _a[3], mid);
          }
        }
        if (x == 1) {
          if (i >> 1 & 1) {
            put(d[1], _a[3], _a[6], mid);
          } else {
            put(d[1], _a[6], _a[3], mid);
          }
        }
        if (x == 2) {
          if (i >> 2 & 1) {
            put(d[2], _a[5], _a[6], mid);
          } else {
            put(d[2], _a[6], _a[5], mid);
          }
        }
      };
      for (int i = 0; i < 8; i++) {
        auto d = c;
        auto _a = a;
        for (int j = 0; j < 3; j++) {
          op(p[j], i, _a, d);
        }
        int need = 0;    
        for (int i = 0; i < 3; i++) {
          need += std::max(0ll, mid - d[i]);
        }
        if (need <= _a[7]) {
          return true;
        }
      }
    } while (std::next_permutation(p, p + 3));
    return false;
  };
  int ans = 0;
  int l = 0, r = S / 3;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
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