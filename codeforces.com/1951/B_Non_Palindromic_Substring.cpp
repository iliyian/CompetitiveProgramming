#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 321;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::vector<int> h(n + 1), p(n + 1), hr(n + 1);
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * 128 % mod + str[i];
    h[i] %= mod;
    p[i] = p[i - 1] * 128 % mod;
  }
  for (int i = n + 1; i >= 1; i--) {
    hr[i] = hr[i + 1] * 128 % mod + str[i];
    hr[i] %= mod;
  }
  auto ispalin = [&](int l, int r) {
    return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod == (hr[l] - hr[r + 1] * p[r - l + 1] % mod + mod) % mod;
  };
  std::vector<std::vector<int>> s(26, std::vector<int>(n + 1));
  auto issame = [&](int l, int r) {
    return s[str[l] - 'a'][r] - s[str[l] - 'a'][l - 1] == r - l + 1;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      s[j][i] = s[j][i - 1];
      if (str[i] == j + 'a') {
        s[j][i]++;
      }
    }
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (issame(l, r)) {
      std::cout << 0 << '\n';
      continue;
    }
    
  }
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