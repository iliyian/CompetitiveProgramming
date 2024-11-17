// date: 2024-11-12 18:40:32
// tag: 字符串

#include <bits/stdc++.h>
#include <cctype>
#define int long long

constexpr int mod = 1e9 + 9, base = 998244353;

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

int num(char ch) {
  if (isdigit(ch)) {
    return ch - '0';
  } else if (isupper(ch)) {
    return ch - 'A' + 10;
  } else {
    return ch - 'a' + 36;
  }
}

int check(std::string a, std::string b) {
  int n = a.size(), m = b.size();
  a = '#' + a, b = '#' + b;
  std::vector<int> ha(n + 1), hb(m + 1);
  int p = 1;
  auto get = [&](int l, int r, const std::vector<int> &v) {
    return (v[r] - v[l - 1] + mod) % mod * qpow(inv(base), l - 1) % mod;
  };
  for (int i = 1; i <= n; i++) {
    ha[i] = ha[i - 1] + p * num(a[i]) % mod;
    ha[i] %= mod;
    p = p * base % mod;
  }
  p = 1;
  for (int i = 1; i <= m; i++) {
    hb[i] = hb[i - 1] + p * num(b[i]) % mod;
    hb[i] %= mod;
    p = p * base % mod;
  }
  int len = std::min(n, m);
  for (int i = len; i >= 1; i--) {
    if (get(n - i + 1, n, ha) == get(1, i, hb)) {
      return i;
    }
  }
  return 0;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i > 1) {
      int len = check(a[i - 1], a[i]);
      std::cout << a[i].substr(len, a[i].size() - len);
    } else {
      std::cout << a[i];
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}