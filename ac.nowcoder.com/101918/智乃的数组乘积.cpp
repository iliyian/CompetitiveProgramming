// date: 2025-02-15 11:43:21
// tag: 不是想的不够复杂，而是想的不够简单，哎。神奇贪心，为什么能贪啊？
// 两次零的特判，x为0时要求不能为0，x不为0时可以都改成0，此时为0则也前后必不能

#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}

int inv(int x, int p) {
  return qpow(x, p - 2, p);
}

void solve() {
  int n, p, x;
  std::cin >> n >> p >> x;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (x == 0) {
    for (int i = 1; i <= n; i++) {
      std::cout << (a[i] ? a[i] : 1) << ' ';
    }
    std::cout << '\n';
    return;
  }
  int y = 1, invx = inv(x, p);
  std::set<int> s;
  s.insert(1);
  for (int i = 1; i <= n; i++) {
    y = y * a[i] % p;
    if (a[i] == 0) {
      s.clear();
      s.insert(1);
      y = 1;
    } else if (s.count(y * invx % p)) {
      a[i] = 0;
      s.clear();
      s.insert(1);
      y = 1;
    } else {
      s.insert(y);
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
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