#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, a;
  std::cin >> n >> a;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + (str[i] == '1');
  }
  for (int i = a; i <= n; i++) {
    if (s[i] - s[i - a] == a) {
      std::cout << n << '\n';
      return;
    }
    if (i >= a + 1 && s[i] - s[i - a - 1] == 0) {
      std::cout << n << '\n';
      return;
    }
  }
  int ans = std::ranges::count(str, '1');
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