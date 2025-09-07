#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    ans ^= a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    b[i] ^= a[i];
  }
  std::string str;
  std::cin >> str;
  // std::cerr << ans << '\n';
  std::vector<std::array<int, 3>> v;
  for (int w = 60; w >= 0; w--) {
    int f = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (b[i] >> w & 1) {
        if (!f) {
          f = b[i];
          v.push_back({b[i], str[i], w});
          b[i] = 0;
        } else {
          b[i] ^= f;
        }
      }
    }
  }
  for (auto [val, s, w] : v) {
    if (s ^ '0' ^ (ans >> w & 1)) {
      ans ^= val;
    }
  }
  std::cout << ans << '\n';
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