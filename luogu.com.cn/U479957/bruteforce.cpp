#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 5e5;

std::vector<int> a(N + 1);

signed main(int argc, char **argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  if (argc > 2) freopen(argv[2], "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  auto start = std::chrono::high_resolution_clock::now();

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] &= 1;
  }
  for (int i = 1; i <= m; i++) {
    int op, l, r, x;
    std::cin >> op;
    if (op == 1 || op == 3) {
      std::cin >> l >> r >> x;
      if (x & 1) {
        for (int i = l; i <= r; i++) {
          a[i] ^= 1;
        }
      }
    } else if (op == 2) {
      std::cin >> l >> r >> x;
      if (x & 1 ^ 1) {
        for (int i = l; i <= r; i++) {
          a[i] = 0;
        }
      }
    } else {
      std::cin >> l >> r;
      int cnt = 1, ans = 1;
      for (int i = l + 1; i <= r; i++) {
        if (a[i] != a[i - 1]) {
          cnt++;
        } else {
          cnt = 1;
        }
        ans = std::max(ans, cnt);
      }
      std::cout << ans << '\n';
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::cerr << std::chrono::duration<double, std::milli>(end - start) << '\n';

  return 0;
}