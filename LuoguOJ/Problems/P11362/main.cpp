// date: 2024-12-06 22:14:45
// tag: 数学，计数dp，独立性，乘法原理

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}

std::map<int, int> mp;

void solve() {
  mp.clear();
  int n, m, v;
  std::cin >> n >> m >> v;
//   std::vector<int> a(n + 1);
  bool f = true;
  // std::vector<int> vec;
  for (int i = 1; i <= m; i++) {
    int x, v;
    std::cin >> x >> v;
    if (!f) continue;
    if (f && mp.count(x) && mp[x] != v) {
      f = false;
    } else {
      mp[x] = v;
      // vec.push_back(x);
    }
  }
  if (!f) {
    std::cout << 0 << '\n';
    return;
  }
  // std::sort(vec.begin(), vec.end());
  // vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  int prv = 0;
  int ans = qpow(v, 2 * (mp.begin()->first - 1));
  // int ans = 1;
  for (auto [x, y] : mp) {
    if (!prv) {
      prv = x;
      continue;
    }
  // for (int i = 1; i < vec.size(); i++) {
    // int len = vec[i] - vec[i - 1];
    int len = x - prv;
    int cur = qpow(v, len - 1) * (v - 1) % mod;
    cur = ((qpow(v, 2 * len) - cur) % mod + mod) % mod;
    ans = ans * cur % mod;
    prv = x;
  }
  // std::cout << vec.front() << ' ' << vec.back() << ' ' << n << '\n';
  ans = ans * qpow(v, 2 * (n - mp.rbegin()->first)) % mod;
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}