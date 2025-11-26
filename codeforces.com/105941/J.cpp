#include <bits/stdc++.h>
#define int long long

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

void solve() {
  std::string s;
  std::cin >> s;
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    auto t = s;
    for (char &c : t) {
      c = (c - 'A' + i) % 26;
    }
    int sum = 0;
    for (char c : t) {
      sum += holes_cnt[c];
    }
    ans = std::max(ans, sum);
  }
  std::cout << ans << '\n';
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