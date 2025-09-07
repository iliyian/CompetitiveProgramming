#include <bits/stdc++.h>
#define int long long

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    std::string s;
    if (__builtin_popcountll(i) != 8) continue;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        s.push_back(str[j]);
      }
    }
    auto y = std::stoll(s.substr(0, 4));
    auto m = std::stoll(s.substr(4, 2));
    auto d = std::stoll(s.substr(6, 2));
    int lim = month[m];
    if (m <= 12 && y != 0 && m >= 1) {
      if (y % 4 == 0 && (y % 100 || y % 400 == 0) && m == 2) {
        lim = 29;
      }
      if (d <= lim && d >= 1) {
        ans++;
        // std::cerr << s << '\n';
      }
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