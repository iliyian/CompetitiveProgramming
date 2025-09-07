// date: 2025-08-12 00:02:37
// tag: 结论：可以通过shift任意固定的偶数长度的区间，达到交换仅交换任意相邻元素的目的。（很难构造就是了
// 结论：shift奇数长度的区间不会导致逆序对改变，因为相当于swap偶数次

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<int> vec = {LLONG_MIN};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vec.push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    vec.push_back(b[i]);
  }
  std::ranges::sort(vec);
  for (int i = 1; i <= n; i++) {
    a[i] = std::ranges::lower_bound(vec, a[i]) - vec.begin();
    b[i] = std::ranges::lower_bound(vec, b[i]) - vec.begin();
  }
  if (k == 1) {
    std::cout << (a == b ? "YES" : "NO") << '\n';
    return;
  }
  if (k == n) {
    std::vector<int> c = b, p(n * 2 + 1);
    for (int i = 1; i <= n; i++) {
      c.push_back(b[i]);
    }
    int vala = 0, base = 233, mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
      vala = vala * base % mod + a[i];
      vala %= mod;
    }
    p[0] = 1;
    for (int i = 1; i <= n * 2;i++) {
      p[i] = p[i - 1] * base % mod;
      c[i] = c[i - 1] * base % mod + c[i];
      c[i] %= mod;
      if (i >= n + 1) {
        int valb = c[i] - c[i - n] * p[n] % mod + mod;
        valb %= mod;
        if (valb == vala) {
          std::cout << "YES\n";
          return;
        }
      }
    }
    std::cout << "NO\n";
    return;
  }
  auto c = a, d = b;
  std::ranges::sort(c);
  std::ranges::sort(d);
  if (c != d) {
    std::cout << "NO\n";
    return;
  }
  bool f = false;
  for (int i = 1; i <= n - 1; i++) {
    if (c[i] == c[i + 1]) {
      f = true;
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    if (d[i] == d[i + 1]) {
      f = true;
    }
  }
  if (f) {
    std::cout << "YES\n";
    return;
  }
  auto get = [&](std::vector<int> &a) {
    std::vector<int> d(n * 2 + 1);
    auto add = [&](int x, int c) -> void {for (int i = x; i <= n * 2; i += i & -i) d[i] += c;};
    auto query = [&](int x) -> int {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += i - 1 - query(a[i]);
      add(a[i], 1);
    }
    return ans;
  };
  int c0 = get(a), c1 = get(b);
  if (k % 2 == 0) {
    std::cout << "YES\n";
    return;
  }
  std::cout << (c0 % 2 == c1 % 2 ? "YES" : "NO") << '\n';
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