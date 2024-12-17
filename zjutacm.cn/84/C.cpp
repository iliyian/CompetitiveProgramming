#include <bits/stdc++.h>
// #define int __int128

void write(int x) {
  if (x < 10) {
    std::cout << char(x + '0');
    return;
  }
  write(x / 10);
  std::cout << char(x % 10 + '0');
}

std::ostream &operator<<(std::ostream&os, const __int128 &x) {
  write(x);
  return os;
}

void solve(int n) {
// void solve() {
  // int n;
  // std::cin >> n;
  n *= 2;
  std::vector<std::pair<int, int>> ans;
  auto check = [&](int x, int y) {
    if ((x + y - 1) % 2) return;
    int r = (x + y - 1) / 2;
    int l = y - r;
    if (l >= r || l <= 0) return;
    ans.push_back({l, r});
  };
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      check(i, n / i);
      if (i * i != n) {
        check(n / i, i);
      }
    }
  }
  std::sort(ans.begin(), ans.end(), std::greater<>());
  std::cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    // auto [l, r] = ans[i];
    int l = ans[i].first, r = ans[i].second;
    // std::cout << l << ' ' << r << '\n';
    assert((r - l + 1) * (l + r) == n);
    // std::cout << l << ' ' << r;
    for (int j = l; j <= r; j++) {
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }
}

// void solve2(int n) {
//   // n *= 2;
//   for (int l = 1; l <= n; l++) {
//     double len = (1 - l * 2 + sqrtl(l * l * 4 - l * 4 + 1 + 8 * n)) / 2.0;
//     if (len == std::round(len) && len > 1) {
//       std::cout << l << ' ' << (int)(l + len - 1) << '\n';
//     }
//   }
// }

void solve3(int n) {
  int l = 1, r = 1, sum = 1;
  while (l <= n) {
    while (sum < n) sum += ++r;
    if (sum == n && l != r) {
      std::cout << l << ' ' << r << '\n';
    }
    sum -= l++;
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  long long t = 1;
  std::cin >> t;
  // for (int i = 1e9 - t; i <= 1e9; i++) {
  // while (t--) {
    // solve(i);
    // std::cout << i << ":\n";
    solve(t);
    // solve3(t);
    // std::cout << '\n';
    // solve2(i);
    // std::cout << '\n';
  // }
  return 0;
}