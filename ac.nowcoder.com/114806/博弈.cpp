#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += ((a[i] - a[i - 1]) % 2 == 1);
    int x = (cnt - 1) / 3;
    if (i != 1 && cnt % 3 != 2) x++;
    if (cnt == 0) x = 0;
    std::cout << a[i] - x << ' ';
  }
  std::cout << '\n';
}

std::map<std::array<int, 3>, int> mp;

int solve(int a, int b, int op) {
  if (a == 0) return 0;
  if (mp.count({a, b, op})) return mp[{a, b, op}];
  if (b == 0) {
    if (a == 1) return 0;
    return mp[{a, b, op}] = solve(a - 2, b + 1, op ^ 1);
  }
  if (op == 0) { // A
    int ans = solve(a - 1, b, op ^ 1) + 1;
    if (b >= 2) {
      ans = std::min(ans, solve(a, b - 1, op ^ 1));
    }
    if (a >= 2) {
      ans = std::min(ans, solve(a - 2, b + 1, op ^ 1));
    }
    return mp[{a, b, op}] = ans;
  } else {
    int ans = solve(a - 1, b, op ^ 1) + 1;
    if (b >= 2) {
      ans = std::max(ans, solve(a, b - 1, op ^ 1));
    }
    if (a >= 2) {
      ans = std::max(ans, solve(a - 2, b + 1, op ^ 1));
    }
    return mp[{a, b, op}] = ans;
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int a = 1; a <= 10; a++) {
  //   for (int b = 1; b <= 10; b++) {
  //     for (int op = 0; op < 1; op++) {
  //       std::cout << a << ' ' << b << ' ' << op << ' ' << solve(a, b, op) << '\n';
  //     }
  //   }
  // }

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}