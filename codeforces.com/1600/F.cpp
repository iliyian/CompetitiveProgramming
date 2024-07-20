// date: 2024-07-16 10:54:46
// tag: 拉姆齐定理，概率

#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  std::set<int> s;
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    s.insert(l * n + r);
    s.insert(r * n + l);
  }

  // if (n <= 48) {
  //   for (int a = 1; a <= n; a++) {
  //     for (int b = a + 1; b <= n; b++) {
  //       if (s.count({a, b})) continue;
  //       for (int c = b + 1; c <= n; c++) {
  //         if (s.count({a, c}) || s.count({b, c})) continue;
  //         for (int d = c + 1; d <= n; d++) {
  //           if (s.count({a, d}) || s.count({b, d}) || s.count({c, d})) continue;
  //           for (int e = d + 1; e <= n; e++) {
  //             if (s.count({a, e}) || s.count({b, e}) || s.count({c, e}) || s.count({d, e})) continue;
  //             std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
  //             return 0;
  //           }
  //         }
  //       }
  //     }
  //   }

  //   for (int a = 1; a <= n; a++) {
  //     for (int b = a + 1; b <= n; b++) {
  //       if (!s.count({a, b})) continue;
  //       for (int c = b + 1; c <= n; c++) {
  //         if (!s.count({a, c}) || !s.count({b, c})) continue;
  //         for (int d = c + 1; d <= n; d++) {
  //           if (!s.count({a, d}) || !s.count({b, d}) || !s.count({c, d})) continue;
  //           for (int e = d + 1; e <= n; e++) {
  //             if (!s.count({a, e}) || !s.count({b, e}) || !s.count({c, e}) || !s.count({d, e})) continue;
  //             std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';              
  //             return 0;
  //           }
  //         }
  //       }
  //     }
  //   }

  //   std::cout << -1 << '\n';
  //   return 0;
  // };

  std::mt19937 rd(std::random_device{}());

    auto id = [&n](int l, int r) {
      return l * n + r;
    };

    auto check = [&](std::array<int, 5> arr) -> bool {
      bool f = true, g = true;
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
          if (arr[i] == arr[j]) return false;
          if (s.count(id(arr[i], arr[j]))) {
            f = false;
          } else {
            g = false;
          }
        }
      }
      return f | g;
    };

    int cnt = 0;
    int lim = 1e6;
    for (int i = 0; i < lim; i++) {
      std::array<int, 5> arr;
      for (int &j : arr) {
        j = rd() % n + 1;
      }
      if (check(arr)) {
        for (auto j : arr) {
          std::cout << j << ' ';
        }
        return 0;
      }
    }

    end:
  // std::vector<int> a(6);
  // // a = {0, 1, 2, 3, 5, 6};
  // for (int i = 1; i <= 1e6; i++) {
  //   for (int j = 1; j <= 5; j++) {
  //     a[j] = rd() % n + 1;
  //   }
  //   bool f = true, g = true, h = true;
  //   for (int j = 1; j <= 5; j++) {
  //     for (int k = 1; k < j; k++) {
  //       if (a[j] == a[k]) {
  //         h = false;
  //         break;
  //       }
  //       if (s.count(a[j] * n + a[k])) {
  //         g = false;
  //       } else {
  //         f = false;
  //       }
  //     }
  //     if (!h) break;
  //   }
  //   if (!h) {
  //     i--;
  //     continue;
  //   }
  //   if (f || g) {
  //     for (int j = 1; j <= 5; j++) {
  //       std::cout << a[j] << ' ';
  //     }
  //     return 0;
  //   }
  // }
  std::cout << -1 << '\n';

  return 0;
}