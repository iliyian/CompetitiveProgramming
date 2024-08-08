// date: 2024-08-08 15:39:54
// tag: 暴力，gcd性质，辗转相减

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int rcalc(int x, int y) {
  if (x == 0) return 0;
  return 1 + rcalc(y, std::abs(y - x));
}

int calc(int x, int y) {
  if (x == 0) return 0;
  if (y && x % y == 0) {
    if (x / y % 2 == 0) {
      return x / y / 2 * 3;
    } else {
      return x / y / 2 * 3 + 2;
    }
  }
  if (y && x > y * 3) {
    int t = (x - y) / (2 * y);
    x -= t * 2 * y;
    return calc(x, y) + 3 * t;
  }
  return 1 + calc(y, std::abs(y - x));
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::vector<int> c(n + 1), m(n + 1);
  int mn = 0;
  for (int i = 1; i <= n; i++) {
    c[i] = calc(a[i], b[i]);
    m[i] = c[i] % 3;
    mn = std::min(mn, c[i]);
  }
  int j = 0;
  for (; j <= n; j++) {
    if (a[j] || b[j]) {
      break;
    }
  }
  if (j <= n) {
  for (int i = 1; i <= n; i++) {
    if (m[i] != m[j] && (a[i] || b[i])) {
      std::cout << "NO\n";
      return;
    }
  }
  }
  std::cout << "YES\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}