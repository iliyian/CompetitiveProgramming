// date: 2025-04-21 21:23:12
// tag: 字符串真难，回文串性质。

#include <bits/stdc++.h>
#define int long long

// constexpr int mod = 1e9 + 321;
constexpr int mod = 1e9 + 7;

void solve() {
  std::string str;
  std::cin >> str;
  auto r = str;
  std::reverse(r.begin(), r.end());
  int n = str.size();
  str = '#' + str;
  r = '#' + r;
  std::vector<int> h(n + 1), p(n + 1), hr(n + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * 128 % mod + str[i];
    h[i] %= mod;
    hr[i] = hr[i - 1] * 128 % mod + r[i];
    hr[i] %= mod;
    p[i] = p[i - 1] * 128 % mod;
  }
  auto get = [&](int l, int r, std::vector<int> &h) {
    return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
  };
  auto check = [&](int l, int r) {
    return get(l, r, h) == get(n - r + 1, n - l + 1, hr);
  };
  bool f = true;
  for (int i = 2; i <= n; i++) {
    if (str[i] != str[1]) {
      f = false;
      break;
    }
  }
  if (f) {
    std::cout << "NO\n";
    return;
  }
  if (get(1, n, h) != get(1, n, hr)) {
    std::cout << "YES\n";
    std::cout << 1 << '\n';  
    std::cout << str.substr(1, n) << '\n';
    return;
  }
  for (int i = 2; i <= n - 1; i++) {
    if (!check(1, i) && !check(i + 1, n)) {
      std::cout << "YES\n";
      std::cout << 2 << '\n';
      std::cout << str.substr(1, i) << ' ' << str.substr(i + 1, n - i) << '\n';
      return;
    }
  }
  std::cout << "NO\n";
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