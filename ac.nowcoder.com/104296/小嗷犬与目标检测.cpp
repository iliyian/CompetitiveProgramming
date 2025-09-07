#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int x) {
  return qpow(x, mod - 2);
}

void solve() {
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  int x3, y3, x4, y4;
  std::cin >> x3 >> y3 >> x4 >> y4;
  if (std::abs(x2 - x1) * std::abs(y2 - y1) > std::abs(x3 - x4) * std::abs(y3 - y4)) {
    std::swap(x1, x3);
    std::swap(y1, y3);
    std::swap(x2, x4);
    std::swap(y2, y4);
  }
  int s1 = std::abs(x2 - x1) * std::abs(y2 - y1);
  int s2 = std::abs(x4 - x3) * std::abs(y4 - y3);
  auto in = [&](int x, int y, int x1, int y1, int x2, int y2) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
  };
  // complete overlap
  if (in(x1, y1, x3, y3, x4, y4) && in(x2, y2, x3, y3, x4, y4)) {
    std::cout << s1 * inv(s2) % mod << '\n';
    return;
  }
  // absent
  if (
    !in(x1, y1, x3, y3, x4, y4) &&
    !in(x1, y2, x3, y3, x4, y4) &&
    !in(x2, y1, x3, y3, x4, y4) &&
    !in(x2, y2, x3, y3, x4, y4)
  ) {
    std::cout << 0 << '\n';
    return;
  }
  if ()
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