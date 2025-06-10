// date: 2025-05-15 19:37:12
// tag: cf题目码量确实往往很少，所以看了题解再做是真的索然无味了。当你想到一个巨麻烦的做法的时候，那就是你假了。

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

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
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int ans = 1;
  for (int i = 2; i <= n - 1; i++) {
    if (str[i] == '?') {
      ans = ans * (i - 1) % mod;
    }
  }
  std::cout << ans * (str[1] != '?') << '\n';
  while (m--) {
    int x;
    char op;
    std::cin >> x >> op;
    if (x != 1) {
      if (str[x] != '?' && op == '?') {
        ans = ans * (x - 1) % mod;
      } else if (str[x] == '?' && op != '?') {
        ans = ans * inv(x - 1) % mod;
      }
    }
    str[x] = op;
    std::cout << ans * (str[1] != '?') << '\n';
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