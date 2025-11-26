#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    ans[i] = i;
  }
  int prv = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (i == n + 1 || str[i] == '1') {
      std::reverse(ans.begin() + prv + 1, ans.begin() + i - 1 + 1);
      if (prv == i - 2) {
        std::cout << "NO\n";
        return;
      }
      prv = i;
    }
  }
  std::cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
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