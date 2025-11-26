#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  std::vector<int> s(n + 1), rs(n + 2);
  for (int i = 1; i <= n; i++) {
    s[i] = (s[i - 1] + (str[i] == 'a' ? 1 : -1));
  }
  std::vector<std::vector<int>> pos(n * 2 + 1);
  for (int i = n; i >= 1; i--) {
    rs[i] = (rs[i + 1] + (str[i] == 'a' ? 1 : -1));
  }
  for (int i = 1; i <= n + 1; i++) {
    pos[rs[i] + n].push_back(i);
  }
  int ans = n + 1;
  for (int i = 0; i <= n; i++) {
    int minr = std::ranges::upper_bound(pos[-s[i] + n], i) - pos[-s[i] + n].begin();
    if (minr == pos[-s[i] + n].size()) {
    } else {
      ans = std::min(ans, pos[-s[i] + n][minr] - i - 1);
    }
  }
  std::cout << (ans == n ? -1 : ans) << '\n';
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